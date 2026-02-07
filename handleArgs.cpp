#include "handleArgs.h"

extern bool isRecursive;
extern bool displayLineNums;

int handleArgs(char *args){
    if(args[0] != '-'){
        return -1;
    }
    char *currArg = args + 1;

    while(*currArg != ' '){
        switch (*currArg) {
            case 'r' : 
                isRecursive = true;
                break;
            case 'n' :
                displayLineNums = true;
                break;
            default : 
                return -1;
        }
        currArg++;
    }
    return 0;
}
