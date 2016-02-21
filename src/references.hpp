// This class is responsible for any external references to be stored
// in a tldr

#ifndef REFERENCES_HPP
#define REFERENCES_HPP

#include <vector>
#include <string>
#include <iostream>

#include "section.hpp"

class References : public Section {
public:
  References();
  void addReference(const std::string&, const std::string&);
private:
  void print(std::ostream&);
  std::vector<std::string> titles;
  std::vector<std::string> urls;
};

#endif
