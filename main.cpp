/*
 *  STUDY_CLOCK - Study Time Management Application
 *  ------------------------------------------------
 *  Author       : Ngô Nguyễn Đông Quân
 *  Version      : 1.0.0
 *  Created Date : 13/02/2025
 *  Language     : C++
 *  Description  : STUDY_CLOCK is an application that helps track study time,  
 *                 supports scheduling study sessions, and reminds users  
 *                 when it's time to study.
 *  
 *  Copyright    : (C) 2025 Ngô Nguyễn Đông Quân. All rights reserved.
 *  
 *  Notes        :
 *    - Version 1.0.0: Initial project setup with basic time-tracking features.
 *  
 */



#include <iostream>
#include <string.h>
#include "object.h"
#include "instruction.h"
#include "progress.h"

using namespace std;

int main()
{
    string userName;
    User user;
    Timer timer;

    cout << "Enter your name: ";

    while (true)
    {
        getline(cin, userName);
        if (userName.empty())
        {
            cout << "Name cannot be empty. Please enter again: ";
            continue;
        }
        if (userName.find_first_of("/\\:*?\"<>|") != string::npos)
        {
            cout << "Invalid name. Please avoid special characters (/\\:*?\"<>|). Try again: ";
            continue;
        }
        break;
    }

    user = User(userName);
    if (user.loadFromFile())
    {
        cout << "Data loaded successfully.\n";
        user.displayStatus();
    }

    execute(user, timer);
    return 0;
}