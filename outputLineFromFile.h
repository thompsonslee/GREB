#ifndef OUTPUTLINE
#define OUTPUTLINE

#include <iostream>
#include <filesystem>
#include <fstream>

namespace fs = std::filesystem;

int outputLineFromFile(fs::path &filePath, std::string &readString) ;
bool containsSubstring(std::string& line, std::string& substring) ;
void outputLine(std::string &line, fs::path &filePath, int lineNum) ;

#endif 
