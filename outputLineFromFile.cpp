#include "outputLineFromFile.h"

int outputLineFromFile(fs::path &filePath, std::string &readString){
    
    std::ifstream file(filePath);
    if(!file){
        return 1;
    }
    
    std::string line;
    int lineNum = 0;
    


    while(std::getline(file, line)){
        if(containsSubstring(line, readString)){
            std::cout << filePath << " at line " << lineNum << ": " << line << std::endl;
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
