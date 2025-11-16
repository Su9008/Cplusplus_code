#include<iostream>
using namespace std;
#include<string>

// # 55 Class and Object - Polymorphism - Case 1 - Calculator Class
// Case Description: Implement a calculator class that performs operations on two operands,
// using both the normal method and the polymorphism technique.

// Normal implementation
class Calculator
{
public:
    int getResult(string oper)
    {
        if (oper == "+")
        {
            return m_Num1 + m_Num2;
        }
        else if (oper == "-")
        {
            return m_Num1 - m_Num2;
        }
        else if (oper == "*")
        {
            return m_Num1 * m_Num2;
        }
        else
        {
            return -1;
        }
        // If we want to extend new features, we must modify source code
        // In real development, we advocate the Open-Closed Principle
        // Open-Closed Principle: Open for extension, closed for modification
    }
    int m_Num1; // operand 1
    int m_Num2; // operand 2
};

void test01()
{
    Calculator c;
    c.m_Num1 = 10;
    c.m_Num2 = 10;
    cout << c.m_Num1 << " + " << c.m_Num2 << " = " << c.getResult("+") << endl;
    cout << c.m_Num1 << " - " << c.m_Num2 << " = " << c.getResult("-") << endl;
    cout << c.m_Num1 << " * " << c.m_Num2 << " = " << c.getResult("*") << endl;
}

// Implement calculator using polymorphism
// Benefits of polymorphism:
// 1. Clear structure
// 2. High readability
// 3. Better extensibility and maintainability
// Implement calculator abstract class
class AbstractCalculator
{
public:
    virtual int getResult()
    {
        return 0;
    }
    int m_Num1;
    int m_Num2;
};

// Addition calculator class
class AddCalculator : public AbstractCalculator
{
public:
    int getResult()
    {
        return m_Num1 + m_Num2;
    }
};
// Subtraction calculator class
class SubCalculator : public AbstractCalculator
{
public:
    int getResult()
    {
        return m_Num1 - m_Num2;
    }
};
// Multiplication calculator class
class MulCalculator : public AbstractCalculator
{
public:
    int getResult()
    {
        return m_Num1 * m_Num2;
    }
};

void test02()
{
    // Polymorphism usage condition:
    // A base class pointer or reference points to a derived class object

    // Addition
    AbstractCalculator* abc = new AddCalculator;
    abc->m_Num1 = 100;
    abc->m_Num2 = 100;
    cout << abc->m_Num1 << " + " << abc->m_Num2 << " = " << abc->getResult() << endl;
    delete abc; // destroy after use

    // Subtraction
    abc = new SubCalculator;
    abc->m_Num1 = 100;
    abc->m_Num2 = 100;
    cout << abc->m_Num1 << " - " << abc->m_Num2 << " = " << abc->getResult() << endl;
    delete abc;

    // Multiplication
    abc = new MulCalculator;
    abc->m_Num1 = 100;
    abc->m_Num2 = 100;
    cout << abc->m_Num1 << " * " << abc->m_Num2 << " = " << abc->getResult() << endl;
    delete abc;
}

int main()
{
    //test01();
    test02();
    return 0;
}
