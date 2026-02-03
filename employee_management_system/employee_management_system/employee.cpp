#include "employee.h"

// Constructor
Employee::Employee(int id, string name, int dId) // #06
{
    this->m_Id = id;
    this->m_Name = name;
    this->m_DeptId = dId;
}

// Display personal information
void Employee::showInfo()  // #06
{
    cout << "Employee ID: " << this->m_Id
        << "\tName: " << this->m_Name
        << "\tPosition: " << this->getDeptName()
        << "\tResponsibility: Complete tasks assigned by the manager" << endl;
}

// Get position name
string Employee::getDeptName()  // #06
{
    return string("Employee");
}
