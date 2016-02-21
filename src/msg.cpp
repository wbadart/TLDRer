// All strings end WITHOUT '\n'
// see header for reasoning

#include "msg.hpp"

const std::string Msg::help {
R"(Usage: tldrer [OPTION]... CMD
Append to an existing tldr, or create a new one
Only one command at a time is supported

Running without a cmd will result in an error

  -d, --description        (Re)Set the TLDR description to user input
  -e, --examples=NUM       The user is prompted for NUM examples: descriptions
                           and code.
  -r, --references=NUM     The user is prompted for NUM references: titles and
                           urls.
      --help     display this help and exit
      --version  output version information and exit
      --pbui     lol

Go Irish!)"
};

const std::string Msg::version {
R"(tldrer 2.0
Written on behalf of University of Notre Dame CSE 20189
License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>
This is free software: you are free to change and redistribute it.
There is NO WARRANTY, to the extent permitted by law.
Written by William Badart and Conrad Bailey)"
};

const std::string Msg::fileOptionRequired {
  "Error: No filename was found in command"
};

const std::string Msg::negativeOptionArg {
  "Error: Optional arguments must be > 0"
};

const std::string Msg::noCommandNameGiven {
  "Error: No filename given for editing"
};

const std::string Msg::multipleFilenamesGiven {
  "Error: Too many filenames given"
};

const std::string Msg::badFile {
  "Error: Could not open file correctly"
};

const std::string Msg::badOptions {
  "Error: Options could not be handled appropriately"
};

const std::string Msg::corruptedMetaData {
  "Error: The section position metadata doesn't exist or has been corrupted"
};

// Prompts end in \n as a matter of convention
const std::string Msg::descriptionPrompt {
  "Type description below and press enter:\n"
};

const std::string Msg::exampleDescriptionPrompt {
  "Type example description below and press enter:\n"
};

const std::string Msg::exampleCodePrompt {
  "Type example code or statement below and press enter:\n$ "
};

const std::string Msg::urlPrompt {
  "Type the address that the link should target and press enter:\n"
};

const std::string Msg::displayTextPrompt {
  "Type the text that should be displayed for the link and press enter:\n"
};

const std::string Msg::suggestHelp {
  "Try 'tldrer -h' for more information."
};

const std::string Msg::badFileName {
  "Error: Bad filename, does not end in \".md\""
};

std::string Msg::invalidOption(const std::string& option) {
  return "tldrer: invalid option -- '" + option + '\'';
}




























































































































const std::string Msg::pbui {
  R"(
                                NNMMyNMNdMMmhMMMMMMNMMMMMNNMM
                              NmNMmmMMMMMMMMMMMMMMMMMMMMMMNmdMNMMM
                           MdMNdNMMMMMMMMMMMMMMMMMMMMMMMMMMMMNNMMMMMM
                         MmMdMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMmN
                       MMdNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNNm
                     NNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNM
                    MdmMMMMMMMMMMMMMMMMMMMMMMMMMMNNNMNNNMMMMMMMMMMMMMMMMmy
                    MMMMMMMMMMMMMMMMMMMMMMMMNNNNNNNNNmdmmmNNNNNNMMMMMMMMMMM
                   MMMMMMMMMMMMMMNNNNNNNNmmmmmdddddddhyyyhhddmmNMMMMMMMMMMMM
                   MMMMMMMMMNNmmmdddhhyyyssoooooooo+++++++++sydmNMMMMMMMMMMM
                   MMMMMMMNdhhhyssoo+++////////:::::::::-:::/+ydmNNNMMMMMMMMMM
                   MMMMMMMdyyssoo++++/////::::::::----------:/oydmNNMMMMMMMMMMy
                   MMMMMMmysssooo++++/////:::::::---.....----:+ydmmNNMMMMMMMMMMM
                   MMMMMNdyssssoo+++//////::::::--.........--:+yddmNNMMMMMMMMMMM
                   MMMMMmhyssssoo++//////:::::::--.........--:+yhdmmmNNMMMMMMMmNM
                   MMMMNmhsssssso+++/////:::::::--..........-:+yhddmmNNNNMMMMMNMM
                   MMMMNmyssssssoo+++/////:::::::---------.-.-+syhdmmmNNNNNMMNmMM
                   MMMMmhysssssso+++//////::::::::------------:/oyhdmmmmNNNNMdmMM
                   MMMNhyysyyyyso+///////:::://::--:://:---------:+sdmmmmmmhhhmMM
                   dMMdyyyhdmmmmdhyo+//:///://+++osyyys+++//::----:/sdmmdds//+osN
                   hNMhsyhdhhhyyyyhhyso//////oo+++++//:---::::----::+hmdy+:-:+/sN
                   smNhssyysssssssssyssoo+//////+ossyyso+/:--------:/hmh+:---//sN
                   dmNhsssyyhdmmNNmddhyys+//:::+oyddmNmhyo+/::----::/yds:///::/sN
                   mdmdssyyyhhyyhhysyssyso/:-.-:/ossso+:::--------:::oho:.-//:/hM
                   mdmdyssso+ooooo+++ossso+::----://////::--...----::/oo:-.://+yN
                   dyddysso+////+/++ossyso+/:::--::://:::--....----::::://:://sd
                      mdhysso++/////+osyyso++/:::::://+/::--..`..---:::--:::::/sm
                      mhyyssoo++///+shhysso+/:-.--:::/oo+:--.``.------::-::::/ym
                      Ndyyssso+////ohdhyyhyo+////++////sso/:-...------::::/ydN
                       Nmhsssoo+//+osyyhhhhhys+///::---:+ys/:----------:::/y
                         dysssoo+++osyyyysso++++/::----:/oyy/:--------:::/s
                         Nysssso+++shyyyyysssoo++//////++osso::------::::+sh
                          dssssso++oyhdmmhyss++::::/+oyhy+///::::----:://+d
                          myssssso++syhmmdhyso++++++///:::::::::::-::://++sm
                           Nyssssssooyyyyysoo+o++/--------:--::::::::///+++:om
                            Ndssyyyssssssssoooooo+/:---------::::::////+/+my-.+d
                             Nohyyyyssssoooo+++//:::--------:::::////////+mm+```:d
                                mhyyyyssoo+++///::---------::::///++/////+dN+````-yN
                                  dyhyyssoo+++///::-----:::////++++//////+dm:````../md
                                  Ndhhyyyyssoo++/////////++++++++///:::::omy.```````:+dmN
                                 myhddhhhyhyyysssssssoooooooo++///:::-::/dd:`````````.-:/+ydN
                                 dohmNhyyyyhhhhhhhhyyysssoo++///:::-::-/yd/```````````.---..-/sdN
                                NmshmNmyyyyyyyyyyyyyssoo++////::::----:sy/````````````.::.```...-+y
                              NmssoydNNdyysyssyyssoo+++////::::::----/so/.`````````````-/.``.......
                            Ndoyo++osdNNhyysssssssoo++/////::::::--:+so:.``````````````-+-```....--
                          Ndyso+/:://odNmyyssssssoo++////:::::::::/oso:-```````````````-+:```..----
                      NNdhysss+/:----:+dNdyysssssoo++///::::::://+syo/:.```````````````:o:.```.--::
                  Ndhssssyyyso/:--....-+dNdyyssssoo++////::////++shs//-````````````````-o/.```.--:/
                dho+ooosyhyso+/::/-.```./hmdhyssssoo+++//////++oydy/::.````````````````-++-```.--::
           N d/o+osssosyhhys+/+hmNd+:....-+hdhyysssooo++++++oosyhy/--.`````````````````.+o:.``.-:::
          d+o+ossssoosyhhyso//ymNNNNmyo++++-:ohhysssoooooooosyys+:.-.``````````````````./o:.```-::/
      NNms++++osssoosyhhhso/:+ydmmmmmdhhdmmy/.-+syyyssssssyyyo/:-:ohs+:.````````````````/s/.```.-/+
    Ndo+++++o++ssoosyhhhys+:/oyhdhhhhhysyyhdhs:.-/shhhhhdhyo:--:ohdddddho/.`````````````:s+-```.-/o
   Ny:/++++os++o++oyyyyys+::+osyyyyssssso+oydhyo/-:smNNdo::--:+syssssyyhddyo/-``````````-so-.`..-+s
  No///++++ss+/++osyyssso/:-+osssso+++ooo+++syyyss+/smN:`...-:os+--:/+++osyhhys/-.``````.oo-...-:oy
doo//////++ss///++ossooo///:/++ooo+////++++//+osssssoyh.`...-/+/:---:::-://+oosyyso/-````/o-...:+ys
sy+//////+oso:://+++++++::///////////:///+++////+sssso:.....:::-...-:-...--:::::/++ooo/-./o:..-/sy+
ms///////+sy+::::://///////::::::///::::////////+osss:..`..---....-:-..`...-----------://++:..-+yy/
yo///////+ss/----::--::////:-:-:::::::::://///+++oso:.``.----....-:--..`...---..--.....-:++:..-+yy/
o+///+///+so:---------::///:------:::::::://///++o+:.``.-------.-::-..`...----.---.....-:+/-.../sy/
o+//++///+o+:---------::///:-------:::::::////++o+-.````--------::-..``..-------.......-://-.`.:sy/
oo//o+/+++o/----------:://:--------:::::::////+oo:`..```...-.--::-...`..--------.......-///-.`.:os/
oo//ss+++oo/----------::::-----------:::::///++o+:``..`.....--::--......--------......-://:-.``-+o/
so//ss+++oo:----------:::------------:::::///++o+-```.......-:/:-......---------......-////:.``./+/
so+/oyooso+:---::----::::------------:::::////+o+-.```.....-::::.......----------.....-://+/-.`.-//
sso/+ysoys+/:::::::--:::----------:::::::::///+o+-........--:::-......-----------....----:++/.``.//
sso++yhsyho/::::::::::::------::::::::::::::///oo-......---:/:-.......-------------..----:/+/:...::
osso+ohyyds////////::::::::--:::::::::::::::/:/oo-......--:/:--......----------::--------:/++/-..--
+oso++yhyhy/////////:::::::::::::::::::::::::::+o-......-:/::--.....------------::::------/+o+/:---
/+sso+shhhs+/////////:::::::::::::::::::::/::::+o:....--::::--......------------:::::::---:+o++/:--
)"
};
