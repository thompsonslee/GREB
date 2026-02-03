#include "recursiveCall.h"

namespace fs = std::filesystem;


int handleRecursiveCall(fs::path &pathStr, std::string& substring){
    fs::path path = fs::path(pathStr);

    if(!fs::is_directory(path)){
        std::cout << pathStr << " is not a directory"<< std::endl;
        return -1;
    }

    if(!fs::exists(path)){
        std::cout << pathStr << " does not exist"<< std::endl;
        return -1;
    }


    fs::recursive_directory_iterator dirs(path);

    for(const fs::directory_entry &p : fs::recursive_directory_iterator(path)){
        if(!p.is_regular_file()){
            continue;
        }
        fs::path path = p.path();

        outputLineFromFile(path, substring);
    }

    return 0;
}
