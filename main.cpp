#include <cstring>
#include <iostream>
#include <filesystem>
#include <string>

#include "recursiveCall.h"
#include "outputLineFromFile.h"

namespace fs = std::filesystem;

int main(int argc, char **argv){

    bool isRecursive = false;
    int stringIndex = -1;
    int fileNameIndex = -1;

    int currArg = 1;
    
    if(argc == 1){
        std::cout << "no arguments provided" << std::endl;
        return 0;
    }

    while(currArg < argc){
        if((std::strcmp(*(argv + currArg), "-r")) == 0){
            isRecursive = true;
            currArg++;
            continue;
        }
        if(fileNameIndex == -1){
            fileNameIndex = currArg;
        }
        else{
            stringIndex = currArg;
        }
        currArg++;
        continue;
    }
    fs::path path = fs::path(*(argv + fileNameIndex));
        std::string stringRead = *(argv + stringIndex);
    if(isRecursive){
        if(handleRecursiveCall(path, stringRead) == -1){
            std::cout << "failed to handle recursive call on " << path << std::endl;            
        }
    }
    else{
        if(outputLineFromFile(path, stringRead) == -1){
            std::cout << "failed to read file " << path << std::endl;
        }
    }
    
}




