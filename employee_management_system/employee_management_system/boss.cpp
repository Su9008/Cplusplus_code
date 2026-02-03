#include "boss.h"

// Constructor
Boss::Boss(int id, string name, int dId) // #07
{
    this->m_Id = id;
    this->m_Name = name;
    this->m_DeptId = dId;
}

// Display personal information
void Boss::showInfo() // #07
{
    cout << "Employee ID: " << this->m_Id
        << "\tName: " << this->m_Name
        << "\tPosition: " << this->getDeptName()
        << "\tResponsibility: Manage all company operations" << endl;
}

// Get position name
string Boss::getDeptName() // #07
{
    return string("Boss");
}
