#pragma once
#include <iostream>
using namespace std;
#include "worker.h"

// Employee class
class Employee : public Worker  // #06
{
public:

    // Constructor
    Employee(int id, string name, int dId);

    // Display personal information
    virtual void showInfo();

    // Get department / position name
    virtual string getDeptName();
};
