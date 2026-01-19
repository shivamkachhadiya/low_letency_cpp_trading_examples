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
        lock_guard<mutex> mtx(g_mutex);
        lt.push_back(i);
        if (i == 500)
        {
            return;
        }
    }
}

void download2()
{
    for (int i = 0; i < SIZE; i++)
    {
        lock_guard<mutex> mtx(g_mutex);
        lt.push_back(i);
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