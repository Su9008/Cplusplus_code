#pragma once // Prevent multiple inclusion of header files
#include <iostream> // Include input/output stream
using namespace std; // Use standard namespace

#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"

#include <fstream>

#define FILENAME "empFile.txt"

class WorkerManager
{
public:
    // Constructor  // #03
    WorkerManager();

    // Display main menu  // #04
    void Show_Menu();

    // Exit the system  // #05
    void ExitSystem();

    // Total number of employees  // #08
    int m_EmpNum;

    // Pointer to employee array  // #08
    Worker** m_EmpArray;

    // Add employee  // #08
    void Add_Emp();

    // Save data to file  // #09
    void save();

    // Flag to indicate whether the file is empty  // #10
    bool m_FileIsEmpty;

    // Get number of employees from file  // #12
    int get_EmpNum();

    // Initialize employee data  // #13
    void init_Emp();

    // Display all employees  // #14
    void Show_Emp();

    // Delete employee  // #16
    void Del_Emp();

    // Check if employee exists
    // If exists, return index in array; otherwise return -1  // #15
    int IsExist(int id);

    // Modify employee information  // #17
    void Mod_Emp();

    // Find employee  // #18
    void Find_Emp();

    // Sort employees by ID  // #19
    void Sort_Emp();

    // Clear data file  // #20
    void Clean_File();

    // Destructor  // #09
    ~WorkerManager();
};
