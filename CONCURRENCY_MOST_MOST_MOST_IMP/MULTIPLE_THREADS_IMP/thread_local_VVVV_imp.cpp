#include <iostream>
#include <thread>
#include <list>
using namespace std;

const int SIZE = 10000;

// each thread will have its own local list
void download(list<int> &local_list)
{
    for (int i = 0; i < SIZE; i++)
    {
        local_list.push_back(i); // NO LOCK NEEDED
    }
}

int main()
{
    list<int> list1; // owned by thread 1
    list<int> list2; // owned by thread 2

    thread th1(download, ref(list1));
    thread th2(download, ref(list2));

    th1.join();
    th2.join();

    // merge results AFTER threads finished
    list<int> global_list;

    global_list.splice(global_list.end(), list1);
    global_list.splice(global_list.end(), list2);

    cout << global_list.size() << endl; // ALWAYS 20000

    return 0;
}
