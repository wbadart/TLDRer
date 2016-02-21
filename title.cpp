// This is a Section derived class which holds the title of the tldr

#include "title.hpp"

Title::Title(const std::string& cmd) :
  Section(cmd)
{}

void Title::set(const std::string& cmd) {
  name = cmd;
}

void Title::print(std::ostream& os) {
  os << "TLDR - " + name + "\n"; // format of first line
  for (auto i = name.length() + 7; i > 0; --i) { // underlining
    os << '=';
  }
  os << "\n\n";
  position = os.tellp(); // record the position of printing
}
