#include "section.hpp"

Section::Section(const std::string& n) :
  name(n)
{}

std::ostream& operator<<(std::ostream& os, Section& section) {
  section.print(os); // calls virtual function, thereby basically
                     // making a "virtual" friend function
  return os;
}
