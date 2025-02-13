#include "object.h"

User::User(string name, int level, int experience)
    : name(name), level(level), experience(experience) {}

void User::addExperience(int minutes)
{
    int points = minutes; 
    experience += points;
    cout << "You studied for " << minutes << " minutes and gained " << points << " experience points.\n";
    while (experience >= 100)
    {
        experience -= 100;
        level++;
        cout << "Congratulations! You leveled up to level " << level << "!\n";
    }
}

void User::displayStatus() const
{
    cout << "\n===== User " << name << " =====\n";
    cout << "1. Level" << level << "\n";
    cout << "2. Experience points: " << experience << "/100\n";
}

void User::saveToFile() const
{
    string filename = name + ".bin"; 
    ofstream file(filename, ios::binary);
    if(file.is_open())
    {
        size_t nameLength = name.size();
        file.write(reinterpret_cast<const char*>(&nameLength), sizeof(nameLength));
        file.write(name.c_str(), nameLength);
        file.write(reinterpret_cast<const char*>(&level), sizeof(level));
        file.write(reinterpret_cast<const char*>(&experience), sizeof(experience));
        file.close();
        cout << "Data saved successfully to " << filename << "!\n";
    }
    else
    {
        cout << "Failed to save data to " << filename << ".\n";
    }
}

bool User::loadFromFile()
{
    string filename = name + ".bin"; 
    ifstream file(filename, ios::binary);
    
    if(file.is_open())
    {
        size_t nameLength;
        file.read(reinterpret_cast<char*>(&nameLength), sizeof(nameLength));

        name.resize(nameLength);
        file.read(&name[0], nameLength);

        file.read(reinterpret_cast<char*>(&level), sizeof(level));
        file.read(reinterpret_cast<char*>(&experience), sizeof(experience));

        file.close();
        return true;
    }
    return false;
}



// ---------------- TIMER ----------------

Timer::Timer() : running(false) {}

void Timer::start()
{
    running = true;
    startTime = steady_clock::now();
    
    cout << "Starting study session...\n";
    this_thread::sleep_for(chrono::milliseconds(200)); 
    
    thread(&Timer::displayClock, this).detach();
}


int Timer::stop()
{
    running = false;
    auto endTime = steady_clock::now();
    auto duration = duration_cast<seconds>(endTime - startTime).count();

    int hours = duration / 3600;
    int minutes = (duration % 3600) / 60;
    int seconds = duration % 60;

    cout << "\nStudy session ended. You studied for ";
    if (hours > 0) cout << hours << "h ";
    cout << minutes << "m " << seconds << "s.\n";

    return minutes;
}


void Timer::displayClock()
{
    while (running)
    {
        auto now = steady_clock::now();
        auto elapsed = duration_cast<seconds>(now - startTime).count();
        
        int minutes = elapsed / 60;
        int seconds = elapsed % 60;

        {
            lock_guard<mutex> lock(coutMutex); 
            cout << "\rTime elapsed: " << setw(2) << setfill('0') << minutes
                 << ":" << setw(2) << setfill('0') << seconds << flush;
        }

        this_thread::sleep_for(chrono::seconds(1));
    }
}
