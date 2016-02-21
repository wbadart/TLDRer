#include <iostream> // cout, cerr
#include <fstream>  // printing to a file
#include <string>   // for better text mainpulation
#include <cctype>   // categorizing characters by type
#include <cstdlib>
#include <getopt.h>

#include "msg.hpp"  // header of messages appropriate for display
#include "tldr.hpp" // class for precise manipulation of the tldr

void getReferences(Tldr& tldr, int number);
void getExamples(Tldr& tldr, int number);
void getDescritption(Tldr& tldr);
bool isInt(char* testArg);

int main(int argc, char* argv[]) {
  opterr = 0; // Tells getopt to shutup. I'll be handling the
              // errors...maybe

  // This is the string of options. Letters followed by a single ':'
  // have a required argument. Letters followed by 2 ':'s have an
  // optional argmuent
  char short_options[] {
    'h', // help
    'd', // rewrite description
    'e',':',':', // add an example, or multiple with option
    'r',':',':', // add a reference, or multiple with option
    '\0' // end of string
  };

  // array of valid long option structs
  // {string, argumentStatus, flagToSet, corresponding Letter}
  static struct option long_options[] =
    {
      {"help",         no_argument,       0, 'h'},
      {"version",      no_argument,       0, 'v'},
      {"description",  no_argument,       0, 'd'},
      {"examples",     optional_argument, 0, 'e'},
      {"references",   optional_argument, 0, 'r'},
      {"pbui",         no_argument,       0, 'p'},
      {0, 0, 0, 0}
    };

  // ints reflecting option arguments
  int doGetDescritption{0}, doGetExamples{0}, doGetReferences{0};
  int option;
  int optionIndex = 0;
  // while there are still options to interpret
  while ((option = getopt_long(argc, argv, short_options, long_options, &optionIndex)) != -1)
    switch (option) {

    case 'h':
      std::cout << Msg::help << std::endl;
      return 0;

    case 'v':
      std::cout << Msg::version << std::endl;
      return 0;

    case 'p':
      std::cout << Msg::pbui << std::endl;
      return 0;

    case 'd':
      doGetDescritption = 1; // non-sensical to make more than one description
      break;

    case 'e': // add examples
      if (optarg == nullptr) { // no argument given for number of examples
        doGetExamples = 1; // default is one if not given optarg
      }
      else {
        if (!isInt(optarg)) { // bad argument given for number of examples
          std::cerr << "tldrer: invalid number of examples: '" << *optarg << '\'' << std::endl;
          return 1;
        }
        // convert the string optArg to a long
        doGetExamples = strtoul(optarg, nullptr, 10);
      }
      break;

    case 'r':
      if (optarg == nullptr) { // no argument given for number of references
        doGetReferences = 1; // default is one if not given optarg
      }
      else {
        if (!isInt(optarg)) { // bad argument given for number of references
          std::cerr << "tldrer: invalid number of references: " << *optarg << '\'' << std::endl;
          return 1;
        }
        // convert the string optArg to a long
        doGetReferences = strtoul(optarg, nullptr, 10);
      }
      break;

      // handle bad options here
    case '?': // when an unknown option is encountered
      // kind of a hack, feel free to improve;
      std::cerr << Msg::invalidOption((char)optopt+"") << std::endl
                << Msg::suggestHelp << std::endl;
      return 1;

    default: // something completely unintelligible was encountered, just quit
      std::cerr << Msg::badOptions << std::endl;
      return 1;

    }

  if (optind == argc) { // only flags and no filename given
    std::cerr << Msg::noCommandNameGiven << std::endl;
    return 1;
  }
  if (optind != argc - 1) { // too many non-option arguments given
    std::cerr << Msg::multipleFilenamesGiven << std::endl;
    return 1;
  }

  Tldr tldr(argv[optind]);

  // process info garnered from flags
  if (doGetDescritption) {
    getDescritption(tldr);
  }
  if (doGetExamples) {
    getExamples(tldr, doGetExamples);
  }
  if (doGetReferences) {
    getReferences(tldr, doGetReferences);
  }

  tldr.writeFile();

  return 0;
}

bool isInt(char* testArg) {
  char* nonInt;
  strtoul(testArg, &nonInt, 10);
  return *nonInt == 0;
}

void getDescritption(Tldr& tldr) {
  std::cout << Msg::descriptionPrompt;
  std::string temp1;
  std::getline(std::cin, temp1);
  tldr.setDescription(temp1);
}

void getExamples(Tldr& tldr, int number) {
  std::string temp1, temp2;
  for (int i{1}; i <= number; ++i) {
    std::cout << "-- Example " << i << " of " << number << " --\n"
              << Msg::exampleDescriptionPrompt;
    std::getline(std::cin, temp1);
    std::cout << Msg::exampleCodePrompt;
    std::getline(std::cin, temp2);
    tldr.addExample(temp1, temp2);
    std::cout << std::endl;
  }
}

void getReferences(Tldr& tldr, int number) {
  std::string temp1, temp2;
  for (int i{1}; i <= number; ++i) {
    std::cout << "-- Reference " << i << " of " << number << " --\n"
              << Msg::displayTextPrompt;
    std::getline(std::cin, temp1);
    std::cout << Msg::urlPrompt;
    std::getline(std::cin, temp2);
    tldr.addReference(temp1, temp2);
    std::cout << std::endl;
  }
}
