// This holds the various strings for display all strings should end
// without a '\n' to allow for finetuned formatting whne utilizing
// this library

#ifndef MSG_H
#define MSG_H

#include <string>

namespace Msg {
  // various errors
  extern const std::string help;
  extern const std::string version;
  extern const std::string pbui;
  extern const std::string fileOptionRequired;
  extern const std::string negativeOptionArg;
  extern const std::string noCommandNameGiven;
  extern const std::string multipleFilenamesGiven;
  extern const std::string badFile;
  extern const std::string badOptions;
  extern const std::string corruptedMetaData;
  extern const std::string suggestHelp;
  extern const std::string badFileName;
  std::string invalidOption(const std::string& option);

  // prompts for user input
  extern const std::string descriptionPrompt;
  extern const std::string exampleDescriptionPrompt;
  extern const std::string exampleCodePrompt;
  extern const std::string urlPrompt;
  extern const std::string displayTextPrompt;
};

#endif
