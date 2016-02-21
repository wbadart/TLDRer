// simple derived class for descriptions of a tldr

#ifndef DESCRIPTION_HPP
#define DESCRIPTION_HPP

#include <iostream>
#include <vector>
#include <string>

#include "section.hpp"

class Description : public Section {
public:
  Description(const std::string& = "");
  void addLine(const std::string&);
private:
  void print(std::ostream& os);
  std::vector<std::string> lines;
};

#endif
