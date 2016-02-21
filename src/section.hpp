// an abstract base class for sections of a tldr each section has a
// name, a position of printing, and printing functions

#ifndef SECTION_HPP
#define SECTION_HPP

#include <iostream>
#include <string>

class Section {
protected:
  std::string name;
public:
  Section(const std::string&);
  int position;
  friend std::ostream& operator<<(std::ostream& os, Section&);
private:
  virtual void print(std::ostream& os) = 0;
};

#endif
