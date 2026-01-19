#include <iostream>
#include <thread>
#include <functional> // std::ref
#include <memory>     // std::unique_ptr
#include <string>

using namespace std;

// pass by val
void passByVal(int x)
{
    x += 5;
    cout << "pass by value x=" << x << endl;
}

void passByRef(int &x)
{
    x += 10;
    cout << "[ass by ref x=]" << x << endl;
}

void multipleArgs(int id, const string &name)
{
    cout << "[multiple args]" << id << "=>" << name << endl;
}

void consumeUniquePtr(unique_ptr<int> ptr)
{
    cout << "[consume unique_ptr]value=>" << *ptr << endl;
}

// lamda with capture
void lambdaExample()
{
    int local = 5;
    thread t([&local]()
             {
        local += 20;
        cout << "[lambda] local=" << local << endl; });
    t.join();
}

// main
int main()
{
    /*---------------- PASS BY VALUE ----------------*/
    cout << "\n\n";
    int a = 10;
    thread t1(passByVal, a);
    t1.join();
    cout << "\nmain a after passbyvalue=" << a << "\n\n";

    /*---------------- PASS BY REFERENCE ----------------*/

    int b = 20;
    thread t2(passByRef, ref(b)); // ref() is mandatory
    t2.join();
    cout << "main b after pass by ref=" << b << "\n\n";

    /*---------------- MULTIPLE ARGUMENTS ----------------*/
    thread t3(multipleArgs, 1, "Downlaoder");
    t3.join();
    cout << endl;

    /*---------------- MOVE-ONLY TYPE ----------------*/
    auto ptr = make_unique<int>(42);
    thread t4(consumeUniquePtr, move(ptr)); // ownership transfer;
    // now ptr is showing null
    if (!ptr)
    {
        cout << "ptr is null becouse it transfer ownership...!!!" << endl;
    }
    t4.join();

    /*---------------- LAMBDA CAPTURE ----------------*/
    lambdaExample();

    return 0;
}
