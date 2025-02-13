#ifndef OBJECT_H
#define OBJECT_H

#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <thread>
#include <chrono>
#include <atomic>
#include <iomanip>
#include <mutex>

using namespace std;
using namespace std::chrono;

class User
{
private:
    string name = 0;
    uint32_t level = 1;
    uint8_t experience = 0;

public:
    User(string name = "Unknown", int level = 1, int experience = 0);
    
    void addExperience(int minutes);
    void displayStatus() const;
    void saveToFile() const;
    bool loadFromFile();
};

class Timer
{
private:
    time_point<steady_clock> startTime;
    atomic<bool> running;
    mutex coutMutex;
    void displayClock();

public:
    Timer();
    void start();
    int stop();
};

#endif // OBJECT_H
