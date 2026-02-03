#include "manager.h"

// Constructor
Manager::Manager(int id, string name, int dId) // #07
{
    this->m_Id = id;
    this->m_Name = name;
    this->m_DeptId = dId;
}

// Display personal information
void Manager::showInfo() // #07
{
    cout << "Employee ID: " << this->m_Id
        << "\tName: " << this->m_Name
        << "\tPosition: " << this->getDeptName()
        << "\tResponsibility: Execute tasks from the boss and assign tasks to employees" << endl;
}

// Get position name
string Manager::getDeptName() // #07
{
    return string("Manager");
}
