#include <iostream>
#include <thread>
#include <future>
#include <vector>
#include <chrono>
#include <list>
#include <mutex>
#include <Windows.h>
using namespace std;

int main()
{
    int cores = thread::hardware_concurrency();
    cout << "Cores=>" << cores << endl;
    return 0;
}