#include <iostream> // cout, cerr
#include <fstream>  // printing to a file
#include <string>   // for better text mainpulation
#include <unistd.h> // "unix std", for getOpt
#include <cctype>   // categorizing characters by type

#include "msg.h"       // header of messages fit for display
#include "tldrManip.h" // library for precise manipulation of the tldr

int main(int argc, char* argv[]) {
  opterr = 0; // Tells getopat to shutup. I'll be handling the errors

  // This is the string of options. Letters followed by a single ':'
  // have a required argument. Letters followed by 2 ':'s have an
  // optional argmuent
  char options[] {
    'h', // help
    'd', // rewrite description
    'e',':',':', // add an example
    'r',':',':', // add a resource
    '\0' // end of string
  };

  // strings to hold text to be inserted
  std::string description, examples, references;
  int option;
  // while there are still options to interpret
  while ((option = getopt(argc, argv, options)) != -1)
    switch (option) {
    case 'h':
      std::cout << Msg::help << std::endl;
      return 0;
    case 'd':
      description = createDescription();
      break;
    case 'e':
      examples = createExamples(optArg);
      break;
    case 'r':
      references = createReferences(optArg);
      break;
    case '?': // when an unknown option is encountered
      if (isprint (optopt)) // if that char is printable
        std::cerr << "Unknown option `-" << optopt << "`" << std::endl;
      else // if not printable print out its hex code
        std::cerr << "Unknown option character `\\x"
                  << std::hex << optopt << "'." << std::endl;
      return 1;
    default: // something completely unintelligible was encountered, just quit
      std::cerr << Msg::badOptions << std::endl;
      return 1;
    }

  if (optind != (argc - 1)) { // something is wrong with the non-option arg
    if (optind == argc) { // only flags and no filename given
      std::cerr << Msg::noFileNameGiven << std::endl;
    }
    else { // Too many non-option args
      std::cerr << Msg::multipleFilenamesGiven << std::endl;
    }
    return 1;
  }
  else { // Nothing is wrong with amount of non-option args
    std::ifstream outputFile{argv[optind]};
    if (outputFile) { // Everything opened correctly

      if (outputFile.peek() == std::ifstream::traits_type::eof()) { // file is empty
        if (!tldrInit(outputFile)) { // User didn't want to make a new file
          return 0;
        }
      }

      if (!description.isEmpty()) {
        if (!addDescription(description, filename)) { // something went wrong
          std::cerr << Msg::missingDescription << std::endl;
          return 1
        }
      }
      if (!examples.isEmpty()) {
        if (!addExamples(examples, filename)) { // something went wrong
          std::cerr << Msg::missingExamples << std::endl;
          return 1;
        }
      }
      if (!references.isEmpty()) {
        if (!addReferences(references, filename)) { // something went wrong
          std::cerr << Msg::missingReferences << std::endl;
          return 1;
        }
      }

      outputFile.close();
    }
    else { // something went wrong opening the file
      std::cerr << Msg::badFileName << std::endl;
      return 1;
    }
  }

  return 0;
}
