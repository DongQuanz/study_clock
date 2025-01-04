#include <iostream>
#include <string.h>
#include <fstream>
#include "input.h"

using namespace std;

void login(char*& name){
    char *temp = new char[256];
    cout << "Enter your username: ";
    cin.getline(temp, 256);
    name = new char[strlen(temp)];
    strcpy(name, temp);
    name[strlen(temp)] = '\0';
    delete[] temp;
}

bool fileExists(const std::string& filepath) {
    std::ifstream file(filepath);
    return file.good();
}

bool load(char* name, int& exp){
    int n = strlen(name);
    char* filepath = new char[n + 5];
    strcpy(filepath, name);
    strcpy(filepath + n, ".txt");
    filepath[n + 4] = '\0';
    if(!fileExists(filepath)) {
        exp = 0;
        return false;
    }
    return true;
}
