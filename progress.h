#ifndef PROGRESS_H
#define PROGRESS_H
#include <iostream>
#include "object.h"
#include "instruction.h"

using namespace std;
using namespace chrono;

void execute(User& user, Timer& timer);
#endif // !PROGRESS_H