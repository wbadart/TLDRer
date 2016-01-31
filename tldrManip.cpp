#include "tldrManip.h"

std::string createDescription() {
  std::cout << Msg::descriptionPrompt << std::endl;
  std::string input; std::cin >> input;
  return input;
}

std::string createExamples(char* optArg) {
  int amount{optArg ? atoi(optArg) : 1);
  std::string exampleDescr, exampleCode, output;
  for (int i{1}; i <= amount; ++i) {
    std::cout << "-- Example " << i << " ---" << std::endl;
    std::cout << Msg::exampleDescrtiptionPrompt << std::endl;
    std::cin >> exampleDescr;
    std::cout << Msg::exampleCodePrompt << std::endl;
    std::cin >> exampleCode;
    std::cout << std::endl;
    output += "- " + exampleDescr + "\n\n" + "    $ " + exampleCode + "\n\n";
  }
  return output;
}

std::string createReferences(char* optArg) {
  int amount{optArg ? atoi(*optArg) : 1);
  std::string url, displayText, output;
  for (int i{1}; i <= amount; ++i) {
    std::cout << "-- Reference " << i << " ---" << std::endl;
    std::cout << Msg::urlPrompt << std::endl;
    std::cin >> url;
    std::cout << Msg::displayTextPrompt << std::endl;
    std::cin >> displayText;
    std::cout << std::endl;
    output += "- [" + displayText + "](" + url + ")\n\n";
  }
  return output;
}
