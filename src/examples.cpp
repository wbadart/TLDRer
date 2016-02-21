#include "examples.hpp"

Examples::Examples() :
  Section("Examples\n--------\n\n")
{}

void Examples::print(std::ostream& os) {
  os << name;
  position = os.tellp();// record position for reading

  //output a line for the description, and a line for the code. The
  // eight spaces before the code gives it "code-like" markdown
  // rendering
  for (std::size_t i{0}; i < descriptions.size(); ++i) {
    os << "- " << descriptions[i] << "\n\n" << "        $ " << code[i] << "\n\n";
  }
}

void Examples::addExample(const std::string& desc, const std::string& cd) {
  code.push_back(cd);
  descriptions.push_back(desc);
}
