#include "path.hpp"

Path::Path(std::string pathstr_in){
    pathstr = pathstr_in;
    std::string tmpdir;
    for(int i = 0; i <= pathstr_in.length(); i++){
        std::cout << "Char " << i << ": " << pathstr_in[i] << std::endl;
        if(pathstr_in[i] == ':' || i == pathstr_in.length()){
            dirs.push_back(tmpdir);
            tmpdir = "";
            continue;
        }
        tmpdir += pathstr_in[i];
    }
}

bool Path::hasfile(std::string fname){
    return false;
}

void Path::addslashes(void){
    std::vector<std::string>::const_iterator dir;
    for(dir = dirs.begin(); dir != dirs.end(); dir++)
        if(dir->back() != '/') dir->push_back('/');
}

void Path::showpath(void){
    std::cout << pathstr << std::endl;
}

void Path::showdirs(void){
    std::vector<std::string>::const_iterator i;
    for(i = dirs.begin(); i != dirs.end(); i++){
        std::cout << *i << std::endl;
    }
}
