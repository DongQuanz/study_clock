#include <iostream>
#include "input.h"
#include "check.h"
#include "instruction.h"

using namespace std;

int main(){
    char* name;
    login(name);

    int exp;
    if(!load(name, exp)){
        cout << "According to the information I looked up, you are a new user, do you need instructions? (Y/N): ";
        if(check_acp()){
            print_help();
        }
    }
    return 0;
}