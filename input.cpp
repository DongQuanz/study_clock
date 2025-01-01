#include <iostream>
#include <string.h>
#include "input.h"

using namespace std;

void login(char *name){
    char *temp = new char[256];
    cout << "Enter your username: ";
    cin.getline(temp, 256);
    name = new char[strlen(temp)];
    strcpy(name, temp);
    delete[] temp;
}
