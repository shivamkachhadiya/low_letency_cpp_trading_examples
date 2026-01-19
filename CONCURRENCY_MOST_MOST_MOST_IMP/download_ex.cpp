#include <iostream>
#include <list>
#include <thread>
using namespace std;

list<int> g_Data;              
const int SIZE = 45000000;

void download()
{
    cout << "[downloader] started download.." << endl;
    for (int i = 0; i < SIZE; ++i)
    {                      
        g_Data.push_back(i);
    }                         
    cout << "[downloader] finished download.." << endl;
}

int main()
{

    cout << "[main] user started an operation.." << endl;
    thread th(download);

    cout << "[main] user started another operation..." << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << i << endl;
    }
    th.join();

    return 0;
}
