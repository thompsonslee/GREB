#include "handleArgs.h"

extern bool isRecursive;
extern bool displayLineNums;
extern bool displayTime;

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
            case 't' :
                displayTime = true;
                break;
            default : 
                return -1;
        }
        currArg++;
    }
    return 0;
}
