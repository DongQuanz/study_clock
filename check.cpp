#include <iostream>
#include "check.h"
using namespace std;

bool check_acp(){
    char c; cin >> c;
    if(c == 'Y' || c == 'y') return true;
    return false;
}