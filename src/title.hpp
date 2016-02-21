// a simple class for the titleing of tldr files

#ifndef TITLE_HPP
#define TITLE_HPP

#include <string>
#include <iostream>

#include "section.hpp"

class Title : public Section {
public:
  Title(const std::string& = "");
  void set(const std::string& cmd);
private:
  void print(std::ostream& os);
};

#endif
