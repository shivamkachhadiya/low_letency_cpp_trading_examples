#include <iostream>
#include <thread>
#include <future>

using namespace std;

void worker(promise<int> p)
{
    int result = 10 + 20;

    // send result to future
    p.set_value(result);
}

int main()
{
    promise<int> p;
    future<int> f = p.get_future();

    thread t(worker, move(p));

    int val = f.get();
    cout << val << endl;

    t.join();
    return 0;
}