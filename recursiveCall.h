#ifndef RECURSIVECALL
#define RECURSIVECALL

#include <iostream>
#include <filesystem>
#include "outputLineFromFile.h"

namespace fs = std::filesystem;

int handleRecursiveCall(fs::path &pathStr, std::string& substring) ;

#endif
