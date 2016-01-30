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
<<<<<<< HEAD
    'e',':',':', // add an example
    'r',':',':', // add a resource
=======
    'e', // add an example
    'r', // add a resource
>>>>>>> c02e290e3b952d34ba893a1cb1ff2f2e01e7ca69
    '\0' // end of string
  };

  // strings to hold text to be inserted
  std::string description, examples, references;
  int option;
<<<<<<< HEAD
  // while there are still options to interpret
  while ((option = getopt(argc, argv, options)) != -1)
    switch (option) {
=======
  while ((option = getopt(argc, argv, options)) != -1)
    switch (option)
      {
>>>>>>> c02e290e3b952d34ba893a1cb1ff2f2e01e7ca69
      case 'h':
        std::cout << Msg::help << std::endl;
        break;
      case 'd':
<<<<<<< HEAD
        createDescription();
        break;
      case 'e':
        addExamples(optArg);
        break;
      case 'r':
        addReference(optArg);
        break;
      case '?': // when an unknown option or missing argument is encountered
        if (isprint (optopt)) // if that char is printable
          std::cerr << "Unknown option `-" << optopt << "`" << std::endl;
        else // if not printable print out its hex code
          std::cerr << "Unknown option character `\\x"
                    << std::hex << optopt << "'." << std::endl;
        return 1; // return 1 to show there was an error
      default: // something completely unintelligible was encountered, just quit
        abort ();
      }

  if (optind != (argc - 1)) { // the next
    if (optind == argc) // only flags and no filename given
      std::cout << Msg::noFileNameGiven << std::endl;

  else if
=======
        writeDescription();
        break;
      case 'e':
        addExample();
        break;
      case 'r':
        addReference();
        break;
      case '?':
        if (isprint (optopt))
          fprintf (stderr, "Unknown option `-%c'.\n", optopt);
        else
          fprintf (stderr,
                   "Unknown option character `\\x%x'.\n",
                   optopt);
        return 1;
      default:
        abort ();
      }

>>>>>>> c02e290e3b952d34ba893a1cb1ff2f2e01e7ca69
  for (int index{optind}; index < argc; ++index)
    std::cout << "Non-option argument " << argv[index] << std::endl;
  return 0;

}
