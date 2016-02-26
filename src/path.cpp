#include "path.hpp"

Path::Path(std::string pathstr_in){
    pathstr = pathstr_in;
    std::string tmpdir;
    for(unsigned int i = 0; i <= pathstr_in.length(); i++){
        std::cout << "Char " << i << ": " << pathstr_in[i] << std::endl;
        if(pathstr_in[i] == ':' || i == pathstr_in.length()){
            dirs.push_back(tmpdir);
            tmpdir = "";
            continue;
        }
        tmpdir += pathstr_in[i];
    }
}

std::string Path::hasfile(std::string fname) const{
    std::vector<std::string>::const_iterator i;
    for(i = dirs.begin(); i != dirs.end(); i++){
        std::cout << "Checking for file: " << (*i + fname) << std::endl;
        std::fstream test(*i + fname);
        if(test) return (*i + fname);
    }
    return "";
}

void Path::addslashes(void){
    std::vector<std::string>::iterator dir;
    for(dir = dirs.begin(); dir != dirs.end(); dir++)
        if((*dir)[dir->length() - 1] != '/') dir->push_back('/');
}

void Path::showpath(void) const{
    std::cout << pathstr << std::endl;
}

void Path::showdirs(void) const{
    std::vector<std::string>::const_iterator i;
    for(i = dirs.begin(); i != dirs.end(); i++){
        std::cout << *i << std::endl;
    }
}
