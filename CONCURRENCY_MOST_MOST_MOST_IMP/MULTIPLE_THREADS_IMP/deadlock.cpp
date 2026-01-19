#include <iostream>
#include <thread>
#include <future>
#include <vector>
#include <chrono>
#include <list>
#include <mutex>
using namespace std;

const int SIZE = 10000;
list<int> lt;
mutex g_mutex;

void download1()
{
    for (int i = 0; i < SIZE; i++)
    {
        g_mutex.lock();
        lt.push_back(i);
        if (i == 500)
        {
            return;
            // deadlock here. unlock not calling
            // without calling unloack fn return.
        }
        g_mutex.unlock();
    }
}

void download2()
{
    for (int i = 0; i < SIZE; i++)
    {
        // this is lock becous t1 unlock not calling
        g_mutex.lock();
        lt.push_back(i);
        g_mutex.unlock();
    }
}

int main()
{
    thread th1(download1);
    thread th2(download2);
    th1.join();
    th2.join();
    cout << lt.size() << endl;

    // NO OUTPUT
    return 0;
}