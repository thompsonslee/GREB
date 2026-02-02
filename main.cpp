#include <cstring>
#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>

int outputLineFromFile(std::string &fileName, std::string &readString) ;

bool containsSubstring(std::string& line, std::string& substring) ;

int main(int argc, char **argv){

    bool isRecursive = false;
    int stringIndex = -1;
    int fileNameIndex = -1;

    int currArg = 1;
    

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
    std::string fileName = *(argv + fileNameIndex);
    std::string stringRead = *(argv + stringIndex);

    int errCode = outputLineFromFile(fileName, stringRead);
    if(errCode == -1){
        std::cout << "failed to read file " << fileName << std::endl;
    }
    
}

int outputLineFromFile(std::string &fileName, std::string &readString){
    std::ifstream file(fileName);
    if(!file){
        return 1;
    }
    
    std::string line;
    int lineNum = 0;

    while(std::getline(file, line)){
        if(containsSubstring(line, readString)){
            std::cout << fileName << " at line " << lineNum << ": " << line << std::endl;
        }
        lineNum++;
    }

    return 0;
}

bool containsSubstring(std::string& line, std::string& substring){
    auto index = line.find(substring);
    if(index == std::string::npos){
        return false;
    }
    return true;
}




