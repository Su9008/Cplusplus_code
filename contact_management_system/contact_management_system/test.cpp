/*
Reference tutorial video:
https://www.bilibili.com/video/BV1et411b73Z?t=0.8&p=72
*/
#include <iostream>
#include <string>
using namespace std;

#define MAX 1000 // Maximum number of contacts

// #01 Contact Management System - System Function Overview
// #02 Contact Management System - Project Creation
// #03 Contact Management System - Menu
// #04 Contact Management System - Exit Function
// #05 Contact Management System - Struct Design
// #06 Contact Management System - Add Contact
// #07 Contact Management System - Show Contacts
// #08 Contact Management System - Check if Contact Exists
// #09 Contact Management System - Delete Contact
// #10 Contact Management System - Search Contact
// #11 Contact Management System - Modify Contact
// #12 Contact Management System - Clear All Contacts

struct Person // #05
{
    string m_Name;
    int m_Sex;  // 1 - Male, 2 - Female
    int m_Age;
    string m_Phone;
    string m_Addr;
};

struct AddressBook // #05
{
    struct Person personArray[MAX];
    int m_Size;
};

void addPerson(AddressBook* abs) // #06
{
    if (abs->m_Size == MAX)
    {
        cout << "The address book is full. Cannot add more contacts!" << endl;
        return;
    }
    else
    {
        string name;
        cout << "Enter name: " << endl;
        cin >> name;
        abs->personArray[abs->m_Size].m_Name = name;

        cout << "Enter gender: " << endl;
        cout << "1 --- Male" << endl;
        cout << "2 --- Female" << endl;
        int sex = 0;
        while (true)
        {
            cin >> sex;
            if (sex == 1 || sex == 2)
            {
                abs->personArray[abs->m_Size].m_Sex = sex;
                break;
            }
            cout << "Invalid input, please enter again: " << endl;
        }

        cout << "Enter age: " << endl;
        int age = 0;
        cin >> age;
        abs->personArray[abs->m_Size].m_Age = age;

        cout << "Enter phone number: " << endl;
        string phone;
        cin >> phone;
        abs->personArray[abs->m_Size].m_Phone = phone;

        cout << "Enter address: " << endl;
        string address;
        cin >> address;
        abs->personArray[abs->m_Size].m_Addr = address;

        abs->m_Size++; // update count
        cout << "Contact added successfully!" << endl;
        system("pause");
        system("cls");
    }
}

void showPerson(AddressBook* abs) // #07
{
    if (abs->m_Size == 0)
    {
        cout << "The address book is empty." << endl;
    }
    else
    {
        for (int i = 0; i < abs->m_Size; i++)
        {
            cout << "Name: " << abs->personArray[i].m_Name << "\t";
            cout << "Gender: " << (abs->personArray[i].m_Sex == 1 ? "Male" : "Female") << "\t";
            cout << "Age: " << abs->personArray[i].m_Age << "\t";
            cout << "Phone: " << abs->personArray[i].m_Phone << "\t";
            cout << "Address: " << abs->personArray[i].m_Addr << endl;
        }
    }
    system("pause");
    system("cls");
}

// Check if contact exists, return index if found, otherwise -1
int isExist(AddressBook* abs, string name) // #08
{
    for (int i = 0; i < abs->m_Size; i++)
    {
        if (abs->personArray[i].m_Name == name)
        {
            return i; // found
        }
    }
    return -1; // not found
}

void deletePerson(AddressBook* abs) // #09
{
    cout << "Enter the name of the contact you want to delete: " << endl;
    string name;
    cin >> name;
    int ret = isExist(abs, name);

    if (ret != -1)
    {
        for (int i = ret; i < abs->m_Size; i++)
        {
            abs->personArray[i] = abs->personArray[i + 1];
        }
        abs->m_Size--;
        cout << "Contact deleted successfully!" << endl;
    }
    else
    {
        cout << "No such contact found." << endl;
    }
    system("pause");
    system("cls");
}

void findPerson(AddressBook* abs) // #10
{
    cout << "Enter the name of the contact you want to search: " << endl;
    string name;
    cin >> name;
    int ret = isExist(abs, name);

    if (ret != -1)
    {
        cout << "Name: " << abs->personArray[ret].m_Name << "\t";
        cout << "Gender: " << (abs->personArray[ret].m_Sex == 1 ? "Male" : "Female") << "\t";
        cout << "Age: " << abs->personArray[ret].m_Age << "\t";
        cout << "Phone: " << abs->personArray[ret].m_Phone << "\t";
        cout << "Address: " << abs->personArray[ret].m_Addr << endl;
    }
    else
    {
        cout << "No such contact found." << endl;
    }
    system("pause");
    system("cls");
}

void modifyPerson(AddressBook* abs) // #11
{
    cout << "Enter the name of the contact you want to modify: " << endl;
    string name;
    cin >> name;
    int ret = isExist(abs, name);

    if (ret != -1)
    {
        cout << "Enter new name: " << endl;
        cin >> abs->personArray[ret].m_Name;

        cout << "Enter gender: " << endl;
        cout << "1 --- Male" << endl;
        cout << "2 --- Female" << endl;
        int sex = 0;
        while (true)
        {
            cin >> sex;
            if (sex == 1 || sex == 2)
            {
                abs->personArray[ret].m_Sex = sex;
                break;
            }
            cout << "Invalid input, please enter again." << endl;
        }

        cout << "Enter age: " << endl;
        int age = 0;
        cin >> age;
        abs->personArray[ret].m_Age = age;

        cout << "Enter phone number: " << endl;
        string phone;
        cin >> phone;
        abs->personArray[ret].m_Phone = phone;

        cout << "Enter address: " << endl;
        string address;
        cin >> address;
        abs->personArray[ret].m_Addr = address;

        cout << "Contact modified successfully!" << endl;
    }
    else
    {
        cout << "No such contact found." << endl;
    }
    system("pause");
    system("cls");
}

void cleanPerson(AddressBook* abs) // #12
{
    int check = 0;
    cout << "!!! Please confirm again before deleting all contacts !!!" << endl;
    cout << "1 --- Confirm delete" << endl;
    cout << "2 --- Cancel" << endl;

    while (true)
    {
        cin >> check;
        if (check == 1)
            break;
        else if (check == 2)
        {
            cout << "!!! Deletion canceled !!!" << endl;
            system("pause");
            system("cls");
            return;
        }
        else
            cout << "Invalid input, please enter again." << endl;
    }

    abs->m_Size = 0;
    cout << "!!! All contacts cleared !!!" << endl;
    system("pause");
    system("cls");
}

void showMenu() // #03
{
    cout << "*********************************" << endl;
    cout << "***** 1. Add Contact ************" << endl;
    cout << "***** 2. Show Contacts **********" << endl;
    cout << "***** 3. Delete Contact *********" << endl;
    cout << "***** 4. Search Contact *********" << endl;
    cout << "***** 5. Modify Contact *********" << endl;
    cout << "***** 6. Clear All Contacts *****" << endl;
    cout << "***** 0. Exit *******************" << endl;
    cout << "*********************************" << endl;
}

int main()
{
    AddressBook abs; // #06
    abs.m_Size = 0;

    int select = 0; // #04 - user input

    while (true) // #04
    {
        showMenu(); // #03
        cin >> select;

        switch (select)
        {
        case 1: // 1. Add Contact  // #06
            addPerson(&abs); // Use address passing to modify the actual data
            break;
        case 2: // 2. Show Contacts  // #07
            showPerson(&abs);
            break;
        case 3: // 3. Delete Contact  // #08 // #09
            deletePerson(&abs);
            break;
        case 4: // 4. Search Contact  // #10
            findPerson(&abs);
            break;
        case 5: // 5. Modify Contact  // #11
            modifyPerson(&abs);
            break;
        case 6: // 6. Clear All Contacts  // #12
            cleanPerson(&abs);
            break;
        case 0: // 0. Exit the Program  // #04
            cout << "Thanks for using the Contact Management System!" << endl;
            system("pause");
            return 0;
        default: // Invalid input handling
            cout << "Invalid selection. Please try again." << endl;
            system("pause");
            system("cls");
            break;
        }
    }

    system("pause");
    return 0;
}
