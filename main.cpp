#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>

#include "msg.h"
#include "tldrManip.h"

int main(int argc, char* argv[]) {
  opterr = 0; // Tells getopat to shutup. I'll be handling the errors

  // This is the string of options. Letters followed by a single ':'
  // have a required argument. Letters followed by 2 ':'s have an
  // optional argmuent
  char options[] {
    'h', // help
    'd', // rewrite description
    'e', // add an example
    'r', // add a resource
    '\0' // end of string
  };

  int option;
  while ((option = getopt(argc, argv, options)) != -1)
    switch (option)
      {
      case 'h':
        std::cout << Msg::help << std::endl;
        break;
      case 'd':
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

  for (int index{optind}; index < argc; ++index)
    std::cout << "Non-option argument " << argv[index] << std::endl;
  return 0;

}
