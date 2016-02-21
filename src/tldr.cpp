#include "tldr.hpp"

Tldr::Tldr(const std::string& cmd) :
  filename((cmd.substr(cmd.length() - 3) == ".md") ?  cmd : cmd + ".md"),
  file(filename),
  title(cmd)
{
  if (!file.is_open()) { // it's a new file
    return;
  }



  // File opened and already has content, gotta parse it. If the file
  // was created with TLDR 2.0 then the last line is guaranteed to
  // have stream positions specifying the locations of section
  // beginnings. Those are relied upon in the code for parsing

  // Best case scenario each position is one character long. -14
  // will take us to the !
  file.seekg(-14, std::ios_base::end);
  while (file.peek() != '!') {
    // goe back one until you find the !
    file.seekg(-1, std::ios_base::cur);
  }
  file.ignore(4); // set buffer to first position, past "!--\n"

  // set the stream positions
  int dp, ep, rp;
  file >> dp >> ep >> rp;

  file.ignore(); // ignore the last '\n' before "-->"
  std::string temp;
  std::getline(file, temp); // retrieve "-->"
  if (temp != "-->") {
    std::cerr << Msg::corruptedMetaData << std::endl;
    exit(EXIT_FAILURE);
  }

  // set the values into the data members
  description.position = dp;
  examples.position = ep;
  references.position = rp;

  // get description content line by line
  file.seekg(description.position);
  while (file.peek() != '\n') {
    std::getline(file, temp);
    description.addLine(temp);
  }

  std::string temp2;
  // get examples line by line
  file.seekg(examples.position);
  while (file.peek() == '-') {
    file.ignore(2); // skip "- "
    std::getline(file, temp);
    file.ignore(11); // skip "\n        $ "
    std::getline(file, temp2);
    examples.addExample(temp, temp2);
    file.ignore(); // skip '\n'
  }

  // get references line by line
  file.seekg(references.position);
  while (file.peek() != '\n') {
    temp = temp2 = "";
    file.ignore(3); // ignore "- ["

    while (file.peek() != ']' && file.peek() != '(') {
      temp += file.get();
    }
    file.ignore(2); // ignore "]("
    std::getline(file, temp2);
    temp2.pop_back(); // delete ')'

    references.addReference(temp, temp2);
    file.ignore(); // skip '\n'
  }

}

Tldr::~Tldr() {
  if (file.is_open()) {
    file.close();
  }
}

void Tldr::setDescription(std::string desc) {
  description = Description(desc);
}

void Tldr::addExample(std::string descr, const std::string& code) {
  examples.addExample(descr, code);
}

void Tldr::addReference(const std::string& descr, const std::string& url) {
  references.addReference(descr, url);
}

void Tldr::writeFile() {
  // close the file, and reopen but "trunc"ate it's contents,
  // i.e. empty the file
  file.close();
  file.open(filename, std::ios_base::trunc | std::ios_base::in | std::ios_base::out);
  // print itself
  file << *this;
}

// flushing is NECESSARY for position recording
std::ostream& operator<<(std::ostream& os, Tldr& tldr) {
  // position recording is done implicity upon printing
  os << tldr.title;
  os.flush();
  os << tldr.description;
  os.flush();
  os << tldr.examples;
  os.flush();
  os << tldr.references;
  os.flush();
  // record the metadata
  os << "\n\n\n\n\n"
     << "<!--\n"
     << tldr.description.position << '\n'
     << tldr.examples.position << '\n'
     << tldr.references.position << '\n'
     << "-->\n";
  return os;
}

