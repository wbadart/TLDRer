// derived from Section, holds titles and urls of external references,
// then formats them for markdown hyperlinking

#include "references.hpp"

References::References() :
  Section("References\n----------\n\n")
{}

void References::addReference(const std::string& title, const std::string& url) {
  titles.push_back("- [" + title + ']'); // markdown formatting for linking text
  urls.push_back('(' + url + ')'); // markdown formating for url of link
}

void References::print(std::ostream& os) {
  os << name;
  position = os.tellp(); // record position of printing
  // loops through each reference
  for (std::size_t i{0}; i < titles.size(); ++i) {
    os << titles[i] << urls[i] << "\n\n";
  }
}
