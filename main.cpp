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