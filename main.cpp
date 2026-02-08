#include <chrono>
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
bool displayTime = false;

const std::string instructions = "usage: greb -[nrt] [file/directory] [string]";

int main(int argc, char **argv){
    int stringIndex = -1;
    int fileNameIndex = -1;

    int currArg = 1;
    
    if(argc == 1){
        std::cout << instructions << std::endl;
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
    if(fileNameIndex == -1 || stringIndex == -1){
        std::cout << instructions << std::endl;
        return 0;
    }
    std::chrono::time_point<std::chrono::high_resolution_clock> start;

    if(displayTime){
        start = std::chrono::high_resolution_clock::now();
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
    if(displayTime){
        auto end = std::chrono::high_resolution_clock::now();
        
        const std::chrono::duration<double> duration = end - start;
        std::cout << "finished in " << duration.count() << " seconds" << std::endl;
    }
    
}






