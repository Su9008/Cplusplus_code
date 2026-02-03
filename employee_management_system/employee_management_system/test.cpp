/*
 Reference tutorial video:
 https://www.bilibili.com/video/BV1et411b73Z?t=8.3&p=147
*/

#include <iostream>
using namespace std;

#include "workerManager.h"
#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"

// #01 Employee Management System - Requirement Analysis and Demo
// #02 Employee Management System - Project Creation
// #03 Employee Management System - Worker Manager Class Design
// #04 Employee Management System - Menu Function Implementation
// #05 Employee Management System - Exit System Function
// #06 Employee Management System - Abstract Worker Class and Employee Class
// #07 Employee Management System - Manager and Boss Class Implementation
// #08 Employee Management System - Add Employee Function
// #09 Employee Management System - File Operations (Write Data)
// #10 Employee Management System - File Operations (Read Data I: File Not Found)
// #11 Employee Management System - File Operations (Read Data II: Empty File)
// #12 Employee Management System - File Operations (Read Data III: Count Employees)
// #13 Employee Management System - File Operations (Read Data IV: Initialization Complete)
// #14 Employee Management System - Display Employee Information
// #15 Employee Management System - Delete Employee (Check Existence)
// #16 Employee Management System - Delete Employee (Implementation)
// #17 Employee Management System - Modify Employee Information
// #18 Employee Management System - Find Employee
// #19 Employee Management System - Sort Employees by ID
// #20 Employee Management System - Clear Data File

int main()
{
    // Instantiate the worker manager object
    WorkerManager wm;

    int choice = 0; // Used to store user's menu selection  // #05

    while (true)  // #05
    {
        // Display the main menu
        wm.Show_Menu(); // #04

        cout << "Enter your choice: " << endl;
        cin >> choice; // Get user input

        switch (choice)
        {
        case 0: // Exit system
            wm.ExitSystem(); // #05
            break;

        case 1: // Add employee
            wm.Add_Emp(); // #08
            break;

        case 2: // Display all employees
            wm.Show_Emp(); // #14
            break;

        case 3: // Delete employee
        {
            wm.Del_Emp();  // #16
            break;
        }

        case 4: // Modify employee information
            wm.Mod_Emp(); // #17
            break;

        case 5: // Find employee
            wm.Find_Emp(); // #18
            break;

        case 6: // Sort employees
            wm.Sort_Emp(); // #19
            break;

        case 7: // Clear data file
            wm.Clean_File(); // #20
            break;

        default:
            system("cls"); // Clear console screen (Windows)
            break;
        }
    }

    system("pause");
    return 0;
}
