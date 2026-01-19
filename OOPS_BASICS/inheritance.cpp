#include <iostream>
using namespace std;

class Base
{
public:
    void log()
    {
        cout << " base log\n";
    }
};

class Derived : public Base
{
public:
    void trade()
    {
        cout << "trading...\n";
    }
};

int main()
{
    Derived d;
    d.log();
    d.trade();
    return 0;
}