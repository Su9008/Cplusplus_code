#pragma once
#include <iostream>
using namespace std;
#include <string>

// Abstract worker class
class Worker  // #06
{
public:

    // Display personal information
    virtual void showInfo() = 0;

    // Get department / position name
    virtual string getDeptName() = 0;

    // Worker ID
    int m_Id;

    // Worker name
    string m_Name;

    // Department ID
    int m_DeptId;
};
