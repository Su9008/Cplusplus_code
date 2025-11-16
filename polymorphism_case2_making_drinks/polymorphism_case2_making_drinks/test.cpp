#include<iostream>
#include<string>
using namespace std;

// # 57 Class and Object - Polymorphism - Case 2 - Making Drinks
// Case Description: The general process of making a drink includes:
// boiling water ¡÷ brewing ¡÷ pouring into cup ¡÷ adding ingredients.
// Use polymorphism to implement this case, providing an abstract base class,
// and derived classes for making coffee and tea.

// Polymorphism Example 2: Making Drinks
class AbstractDrinking
{
public:

    // Pure virtual function (abstract method)
    // "= 0" means this function has NO implementation in the base class.
    // Any class containing at least one pure virtual function becomes an **abstract class**.
    // Abstract classes **cannot be instantiated directly**.
    // Case 2 uses **pure virtual functions**, forcing derived classes
    // (Coffee, Tea) to provide their own implementations.

    // Boil water
    virtual void Boil() = 0;

    // Brew drink
    virtual void Brew() = 0;

    // Pour into a cup
    virtual void PourInCup() = 0;

    // Add extra ingredients
    virtual void PutSomething() = 0;

    // Template method for making a drink
    // This defines the fixed steps for drink preparation.
    // Derived classes only override the individual actions (Boil, Brew...)
    // but cannot change this overall workflow.
    void makeDrink()
    {
        Boil();
        Brew();
        PourInCup();
        PutSomething();
    }
};

// Making Coffee
class Coffee : public AbstractDrinking
{
public:
    virtual void Boil()
    {
        cout << "Boiling Nongfu Spring water" << endl;
    }
    virtual void Brew()
    {
        cout << "Brewing coffee" << endl;
    }
    virtual void PourInCup()
    {
        cout << "Pouring into cup" << endl;
    }
    virtual void PutSomething()
    {
        cout << "Adding sugar and milk" << endl;
    }
};

// Making Tea
class Tea : public AbstractDrinking
{
public:
    virtual void Boil()
    {
        cout << "Boiling mineral water" << endl;
    }
    virtual void Brew()
    {
        cout << "Brewing tea leaves" << endl;
    }
    virtual void PourInCup()
    {
        cout << "Pouring into cup" << endl;
    }
    virtual void PutSomething()
    {
        cout << "Adding goji berries" << endl;
    }
};

void doWork(AbstractDrinking* abs)
{
    abs->makeDrink();
    delete abs; // free memory
}

void test01()
{
    // Make coffee
    doWork(new Coffee);

    cout << "--------------" << endl;

    // Make tea
    doWork(new Tea);
}

int main()
{
    test01();
    return 0;
}

