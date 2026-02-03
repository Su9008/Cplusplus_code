#pragma once
#include <iostream>
using namespace std;
#include "worker.h"

// Manager class
class Manager : public Worker // #07
{
public:

    // Constructor
    Manager(int id, string name, int dId);

    // Display personal information
    virtual void showInfo();

    // Get department / position name
    virtual string getDeptName();
};
