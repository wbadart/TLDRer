#include "description.hpp"

Description::Description(const std::string& description) :
  Section("Description\n-----------\n\n")
{
  // only keep non-empty lines
  if (description != "") {
    lines.push_back(description);
  }
}

void Description::addLine(const std::string& line) {
  lines.push_back(line);
}

void Description::print(std::ostream& os) {
  os << name;
  position = os.tellp(); // record printing position

  // print it straight up, like a paragraph
  for (const auto& line : lines) {
    os << line << '\n';
  }
  os << '\n';
}
