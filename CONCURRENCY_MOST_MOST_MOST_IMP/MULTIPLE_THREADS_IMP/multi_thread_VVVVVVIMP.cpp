#include <bits/stdc++.h>
using namespace std;

list<int> lt;
mutex mt;

void download()
{
    for (int i = 0; i < 10; i++)
    {
        this_thread::sleep_for(chrono::seconds(1)); 

        {
            lock_guard<mutex> lock(mt);
            lt.push_back(i);
            cout << "Thread-1 pushed: " << i << endl;
        }
    }
}

void download2()
{
    for (int i = 100; i < 110; i++)
    {   
        {
            lock_guard<mutex> lock(mt);
            lt.push_back(i);
            cout << "Thread-2 pushed: " << i << endl;
        }
        this_thread::sleep_for(chrono::seconds(1));
    }
}

int main()
{
    thread th1(download);
    thread th2(download2);

    cout << "Main is free and running..." << endl;

    for (int i = 0; i < 5; i++)
    {
        cout << "Main doing other work..." << endl;
        this_thread::sleep_for(chrono::milliseconds(500));
    }

    th1.join();
    th2.join();

    cout << "Final list size: " << lt.size() << endl;
}
