#include <cstring>
#include <iostream>
#include <filesystem>
#include <string>

#include "recursiveCall.h"
#include "outputLineFromFile.h"
#include "handleArgs.h"

namespace fs = std::filesystem;

bool isRecursive = false;
bool displayLineNums = false;

int main(int argc, char **argv){
    int stringIndex = -1;
    int fileNameIndex = -1;

    int currArg = 1;
    
    if(argc == 1){
        std::cout << "no arguments provided" << std::endl;
        return 0;
    }
    
    char *flags = *(argv + 1);
    if(flags[0] == '-'){
        handleArgs(flags);
        currArg++;
    }
    
    while(currArg < argc){
        
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






