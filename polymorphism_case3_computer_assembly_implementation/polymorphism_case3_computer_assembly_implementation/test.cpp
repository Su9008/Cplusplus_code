#include<iostream>
#include<string>
using namespace std;

// # 60 Class and Object - Case 3 - Computer Assembly Implementation

// Abstract component classes
class CPU // Abstract CPU class
{
public:
    // Abstract compute function
    virtual void calculate() = 0;
};
class VideoCard // Abstract video card class
{
public:
    // Abstract display function
    virtual void display() = 0;
};
class Memory // Abstract memory class
{
public:
    // Abstract storage function
    virtual void storage() = 0;
};

// Computer class
class Computer
{
public:
    Computer(CPU* cpu, VideoCard* vc, Memory* mem)
    {
        m_cpu = cpu;
        m_vc = vc;
        m_mem = mem;
    }

    // Work function
    void work()
    {
        // Call component interfaces to make them work
        m_cpu->calculate();
        m_vc->display();
        m_mem->storage();
    }

    // Destructor: release 3 components
    ~Computer()
    {
        // Release CPU
        if (m_cpu != NULL)
        {
            delete m_cpu;
            m_cpu = NULL;
        }
        // Release video card
        if (m_vc != NULL)
        {
            delete m_vc;
            m_vc = NULL;
        }
        // Release memory
        if (m_mem != NULL)
        {
            delete m_mem;
            m_mem = NULL;
        }
    }

private:
    CPU* m_cpu;     // pointer to CPU component
    VideoCard* m_vc;// pointer to video card component
    Memory* m_mem;  // pointer to memory component
};

// Concrete manufacturers
// Intel
class IntelCpu : public CPU
{
    void calculate()
    {
        cout << "Intel CPU starts calculating!" << endl;
    }
};
class IntelVideoCard : public VideoCard
{
    void display()
    {
        cout << "Intel video card starts displaying!" << endl;
    }
};
class IntelMemory : public Memory
{
    void storage()
    {
        cout << "Intel memory starts storing!" << endl;
    }
};

// Lenovo
class LenovoCpu : public CPU
{
    void calculate()
    {
        cout << "Lenovo CPU starts calculating!" << endl;
    }
};
class LenovoVideoCard : public VideoCard
{
    void display()
    {
        cout << "Lenovo video card starts displaying!" << endl;
    }
};
class LenovoMemory : public Memory
{
    void storage()
    {
        cout << "Lenovo memory starts storing!" << endl;
    }
};

void test01()
{
    // First computer
    cout << "First computer starts working" << endl;
    CPU* intelCpu = new IntelCpu;
    VideoCard* intelCard = new IntelVideoCard;
    Memory* intelMem = new IntelMemory;
    Computer* computer1 = new Computer(intelCpu, intelCard, intelMem);
    computer1->work();
    delete computer1;

    // Second computer
    cout << "--------------------------" << endl;
    cout << "Second computer starts working" << endl;
    Computer* computer2 = new Computer(new LenovoCpu, new LenovoVideoCard, new LenovoMemory);
    computer2->work();
    delete computer2;

    // Third computer
    cout << "--------------------------" << endl;
    cout << "Third computer starts working" << endl;
    Computer* computer3 = new Computer(new LenovoCpu, new IntelVideoCard, new LenovoMemory);
    computer3->work();
    delete computer3;
}

int main()
{
    test01();
    return 0;
}
