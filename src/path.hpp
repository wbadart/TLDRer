// Stores and parses a PATH variable to determine if a file exists
// in one of its members

#ifndef PATH_H
#define PATH_h

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

class Path{
public:
    Path(std::string pathstr_in = "./");
    std::string hasfile(std::string) const;
    void showpath(void) const;
    void showdirs(void) const;
    void addslashes(void);
private:
    std::string pathstr;
    std::vector<std::string> dirs;
};
#endif
