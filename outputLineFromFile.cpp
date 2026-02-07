#include "outputLineFromFile.h"

extern bool displayLineNums;

int outputLineFromFile(fs::path &filePath, std::string &readString){
    
    std::ifstream file(filePath);
    if(!file){
        return 1;
    }
    
    std::string line;
    int lineNum = 0;

    while(std::getline(file, line)){
        if(containsSubstring(line, readString)){
            outputLine(line, filePath, lineNum);
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

void outputLine(std::string &line, fs::path &filePath, int lineNum){
     
    std::cout << filePath;
    if(displayLineNums){
        std::cout <<  "at line " << lineNum;
    }

    std::cout << ": " << line << std::endl;
}
