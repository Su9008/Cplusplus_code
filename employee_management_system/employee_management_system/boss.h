#pragma once
#include <iostream>
using namespace std;
#include "worker.h"

// Boss class
class Boss : public Worker // #07
{
public:

    // Constructor
    Boss(int id, string name, int dId);

    // Display personal information
    virtual void showInfo();

    // Get department / position name
    virtual string getDeptName();
};
