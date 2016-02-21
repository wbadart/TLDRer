// Derived from Section, holds exmaples with descriptions and
// corresponding code samples

#ifndef EXAMPLES_HPP
#define EXAMPLES_HPP

#include <iostream>
#include <vector>
#include <string>

#include "section.hpp"

class Examples : public Section {
public:
  Examples();
  void addExample(const std::string& descr, const std::string& code);
private:
  void print(std::ostream& os);
  std::vector<std::string> descriptions;
  std::vector<std::string> code;
};

#endif
