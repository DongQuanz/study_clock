#include "progress.h"

void execute(User &user, Timer &timer)
{
    int choice;
    do
    {
        print_help();
        while (!(cin >> choice))
        {
            cin.clear();                                         
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            cout << "Invalid input. Please enter a number: ";
        }

        switch (choice)
        {
        case 1:
            timer.start();
            break;
        case 2:
        {
            int minutes = timer.stop();
            user.addExperience(minutes);
            break;
        }
        case 3:
            user.displayStatus();
            break;
        case 4:
            user.saveToFile();
            cout << "Goodbye! See you next time.\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);
}