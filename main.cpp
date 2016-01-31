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
        break;
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
        return 1; // return 1 to show there was an error
      default: // something completely unintelligible was encountered, just quit
        abort ();
      }

  if (optind != (argc - 1)) { // something is wrong with the non-option arg
    if (optind == argc) { // only flags and no filename given
      std::cout << Msg::noFileNameGiven << std::endl;
    }
    else { // Too many non-option args
      std::cout << Msg::multipleFilenamesGiven << std::endl;
    }
  }
  else { // Nothing is wrong with amount of non-option args
    std::string filename{argv[optind]};
    if (!description.isEmpty()) {
      addDescription(description, filename);
    }
    if (!examples.isEmpty()) {
      addExamples(examples, filename);
    }
    if (!references.isEmpty()) {
      addReferences(references, filename);
    }
  }

    for (int index{optind}; index < argc; ++index)
    std::cout << "Non-option argument " << argv[index] << std::endl;
  return 0;

}
