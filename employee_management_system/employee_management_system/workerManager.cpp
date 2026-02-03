#include "workerManager.h"

// Constructor  // #08 #10 #11
WorkerManager::WorkerManager()
{
    // 1. File does not exist
    ifstream ifs;
    ifs.open(FILENAME, ios::in); // Open file for reading

    if (!ifs.is_open())
    {
        cout << "File does not exist." << endl;

        // Initialize attributes  // #08
        this->m_EmpNum = 0;
        this->m_EmpArray = NULL;

        // Mark file as empty  // #10
        this->m_FileIsEmpty = true;
        ifs.close();
        return;
    }

    // 2. File exists but contains no data  // #11
    char ch;
    ifs >> ch;
    if (ifs.eof())
    {
        cout << "File is empty." << endl;
        this->m_EmpNum = 0;
        this->m_EmpArray = NULL;
        this->m_FileIsEmpty = true;
        ifs.close();
        return;
    }

    // 3. File exists and contains employee records  // #12
    int num = this->get_EmpNum();
    cout << "Total number of employees: " << num << endl;
    this->m_EmpNum = num;

    // Allocate memory for employee array  // #13
    this->m_EmpArray = new Worker * [this->m_EmpNum];

    // Initialize employee data from file
    this->init_Emp();
}

// Display main menu  // #04
void WorkerManager::Show_Menu()
{
    cout << "******************************************" << endl;
    cout << "***** Welcome to Employee Management *****" << endl;
    cout << "************* 0. Exit System *************" << endl;
    cout << "************* 1. Add Employee ************" << endl;
    cout << "************* 2. Show Employees **********" << endl;
    cout << "************* 3. Delete Employee *********" << endl;
    cout << "************* 4. Modify Employee *********" << endl;
    cout << "************* 5. Find Employee ***********" << endl;
    cout << "************* 6. Sort by ID **************" << endl;
    cout << "************* 7. Clear All Data **********" << endl;
    cout << "******************************************" << endl;
    cout << endl;
}

// Exit system  // #05
void WorkerManager::ExitSystem()
{
    cout << "Thank you for using the system." << endl;
    system("pause");
    exit(0);
}

// Add employee  // #08
void WorkerManager::Add_Emp()
{
    cout << "Enter number of employees to add: " << endl;

    int addNum = 0;
    cin >> addNum;

    if (addNum > 0)
    {
        // New array size = existing employees + new employees
        int newSize = this->m_EmpNum + addNum;

        // Allocate new memory space
        Worker** newSpace = new Worker * [newSize];

        // Copy existing employees to new space
        for (int i = 0; i < this->m_EmpNum; i++)
        {
            newSpace[i] = this->m_EmpArray[i];
        }

        // Add new employees
        for (int i = 0; i < addNum; i++)
        {
            int id;
            string name;
            int dSelect;

            cout << "Enter ID for employee " << i + 1 << ": ";
            cin >> id;

            cout << "Enter name for employee " << i + 1 << ": ";
            cin >> name;

            cout << "Select position:" << endl;
            cout << "1. Employee" << endl;
            cout << "2. Manager" << endl;
            cout << "3. Boss" << endl;
            cin >> dSelect;

            Worker* worker = NULL;
            switch (dSelect)
            {
            case 1:
                worker = new Employee(id, name, 1);
                break;
            case 2:
                worker = new Manager(id, name, 2);
                break;
            case 3:
                worker = new Boss(id, name, 3);
                break;
            default:
                break;
            }

            // Store the new worker pointer in the array
            newSpace[this->m_EmpNum + i] = worker;
        }

        // Release old memory
        delete[] this->m_EmpArray;

        // Update pointer and employee count
        this->m_EmpArray = newSpace;
        this->m_EmpNum = newSize;
        this->m_FileIsEmpty = false;

        cout << "Successfully added " << addNum << " employees." << endl;

        // Save data to file  // #09
        this->save();
    }
    else
    {
        cout << "Invalid input." << endl;
    }

    system("pause");
    system("cls");
}

// Save employee data to file  // #09
void WorkerManager::save()
{
    ofstream ofs;
    ofs.open(FILENAME, ios::out); // Open file for writing

    for (int i = 0; i < this->m_EmpNum; i++)
    {
        ofs << this->m_EmpArray[i]->m_Id << " "
            << this->m_EmpArray[i]->m_Name << " "
            << this->m_EmpArray[i]->m_DeptId << endl;
    }

    ofs.close();
}

// Get number of employees from file  // #12
int WorkerManager::get_EmpNum()
{
    ifstream ifs;
    ifs.open(FILENAME, ios::in);

    int id;
    string name;
    int dId;
    int num = 0;

    while (ifs >> id && ifs >> name && ifs >> dId)
    {
        num++;
    }
    return num;
}

// Initialize employee data from file  // #13
void WorkerManager::init_Emp()
{
    ifstream ifs;
    ifs.open(FILENAME, ios::in);

    int id;
    string name;
    int dId;
    int index = 0;

    while (ifs >> id && ifs >> name && ifs >> dId)
    {
        Worker* worker = NULL;

        if (dId == 1)
            worker = new Employee(id, name, dId);
        else if (dId == 2)
            worker = new Manager(id, name, dId);
        else
            worker = new Boss(id, name, dId);

        this->m_EmpArray[index++] = worker;
    }

    ifs.close();
}

// Display all employees  // #14
void WorkerManager::Show_Emp()
{
    if (this->m_FileIsEmpty)
    {
        cout << "File does not exist or contains no records." << endl;
    }
    else
    {
        for (int i = 0; i < this->m_EmpNum; i++)
        {
            // Polymorphic call
            this->m_EmpArray[i]->showInfo();
        }
    }

    system("pause");
    system("cls");
}

// Delete employee  // #16
void WorkerManager::Del_Emp()
{
    if (this->m_FileIsEmpty)
    {
        cout << "File does not exist or contains no records." << endl;
    }
    else
    {
        cout << "Enter the employee ID to delete: ";
        int id;
        cin >> id;

        int index = this->IsExist(id);
        if (index != -1)
        {
            for (int i = index; i < this->m_EmpNum - 1; i++)
            {
                this->m_EmpArray[i] = this->m_EmpArray[i + 1];
            }

            this->m_EmpNum--;
            this->save();

            cout << "Employee deleted successfully." << endl;
        }
        else
        {
            cout << "Delete failed. Employee not found." << endl;
        }
    }

    system("pause");
    system("cls");
}

// Check if employee exists  // #15
int WorkerManager::IsExist(int id)
{
    for (int i = 0; i < this->m_EmpNum; i++)
    {
        if (this->m_EmpArray[i]->m_Id == id)
        {
            return i;
        }
    }
    return -1;
}

// Modify employee information  // #17
void WorkerManager::Mod_Emp()
{
    if (this->m_FileIsEmpty)
    {
        cout << "File does not exist or contains no records." << endl;
    }
    else
    {
        cout << "Enter the employee ID to modify: ";
        int id;
        cin >> id;

        int ret = this->IsExist(id);
        if (ret != -1)
        {
            delete this->m_EmpArray[ret];

            int newId;
            string newName;
            int dSelect;

            cout << "Employee found. Enter new ID: ";
            cin >> newId;

            cout << "Enter new name: ";
            cin >> newName;

            cout << "Select new position:" << endl;
            cout << "1. Employee" << endl;
            cout << "2. Manager" << endl;
            cout << "3. Boss" << endl;
            cin >> dSelect;

            Worker* worker = NULL;
            if (dSelect == 1)
                worker = new Employee(newId, newName, dSelect);
            else if (dSelect == 2)
                worker = new Manager(newId, newName, dSelect);
            else
                worker = new Boss(newId, newName, dSelect);

            this->m_EmpArray[ret] = worker;
            this->save();

            cout << "Employee updated successfully." << endl;
        }
        else
        {
            cout << "Employee not found." << endl;
        }
    }

    system("pause");
    system("cls");
}

// Find employee  // #18
void WorkerManager::Find_Emp()
{
    if (this->m_FileIsEmpty)
    {
        cout << "File does not exist or contains no records." << endl;
    }
    else
    {
        cout << "Select search method:" << endl;
        cout << "1. Search by ID" << endl;
        cout << "2. Search by name" << endl;

        int select;
        cin >> select;

        if (select == 1)
        {
            int id;
            cout << "Enter employee ID: ";
            cin >> id;

            int ret = IsExist(id);
            if (ret != -1)
            {
                cout << "Employee found:" << endl;
                this->m_EmpArray[ret]->showInfo();
            }
            else
            {
                cout << "Employee not found." << endl;
            }
        }
        else if (select == 2)
        {
            string name;
            cout << "Enter employee name: ";
            cin >> name;

            bool found = false;
            for (int i = 0; i < this->m_EmpNum; i++)
            {
                if (this->m_EmpArray[i]->m_Name == name)
                {
                    this->m_EmpArray[i]->showInfo();
                    found = true;
                }
            }

            if (!found)
            {
                cout << "Employee not found." << endl;
            }
        }
        else
        {
            cout << "Invalid selection." << endl;
        }
    }

    system("pause");
    system("cls");
}

// Sort employees by ID using selection sort  // #19
void WorkerManager::Sort_Emp()
{
    if (this->m_FileIsEmpty)
    {
        cout << "File does not exist or contains no records." << endl;
        system("pause");
        system("cls");
        return;
    }

    cout << "Select sorting order:" << endl;
    cout << "1. Ascending by ID" << endl;
    cout << "2. Descending by ID" << endl;

    int select;
    cin >> select;

    // Selection sort
    for (int i = 0; i < this->m_EmpNum; i++)
    {
        int minOrMax = i; // Index of current min/max element

        for (int j = i + 1; j < this->m_EmpNum; j++)
        {
            // Compare based on selected order
            if ((select == 1 && this->m_EmpArray[minOrMax]->m_Id > this->m_EmpArray[j]->m_Id) ||
                (select == 2 && this->m_EmpArray[minOrMax]->m_Id < this->m_EmpArray[j]->m_Id))
            {
                minOrMax = j;
            }
        }

        // Swap elements if needed
        if (i != minOrMax)
        {
            Worker* temp = this->m_EmpArray[i];
            this->m_EmpArray[i] = this->m_EmpArray[minOrMax];
            this->m_EmpArray[minOrMax] = temp;
        }
    }

    cout << "Sorting completed successfully." << endl;

    // Save sorted result and display
    this->save();
    this->Show_Emp();
}


// Clear all data  // #20
void WorkerManager::Clean_File()
{
    cout << "Are you sure you want to clear all data?" << endl;
    cout << "1. Yes" << endl;
    cout << "2. No" << endl;

    int select;
    cin >> select;

    if (select == 1)
    {
        ofstream ofs(FILENAME, ios::trunc);
        ofs.close();

        for (int i = 0; i < this->m_EmpNum; i++)
        {
            delete this->m_EmpArray[i];
        }

        delete[] this->m_EmpArray;
        this->m_EmpArray = NULL;
        this->m_EmpNum = 0;
        this->m_FileIsEmpty = true;

        cout << "All data cleared successfully." << endl;
    }

    system("pause");
    system("cls");
}

// Destructor  // #09
WorkerManager::~WorkerManager()
{
    if (this->m_EmpArray != NULL)
    {
        delete[] this->m_EmpArray;
        this->m_EmpArray = NULL;
    }
}
