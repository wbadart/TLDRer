// A class for tldrs as objects. the datamembers are straight forward,
// and the member functions (except constructor) are just light
// wrappers

#ifndef TLDR_HPP
#define TLDR_HPP

#include <fstream>
#include <iostream>
#include <cstdlib>

#include "section.hpp"
#include "path.hpp"
#include "title.hpp"
#include "description.hpp"
#include "examples.hpp"
#include "references.hpp"
#include "msg.hpp"

class Tldr {
public:
  Tldr(const std::string& cmd);
  ~Tldr();
  void setDescription(std::string description);
  void addExample(std::string description, const std::string& code);
  void addReference(const std::string& description, const std::string& url);
  void writeFile();
  friend std::ostream& operator<<(std::ostream& os, Tldr&);

private:
  std::string filename;
  std::fstream file;
  Title title;
  Description description;
  Examples examples;
  References references;
};

#endif
