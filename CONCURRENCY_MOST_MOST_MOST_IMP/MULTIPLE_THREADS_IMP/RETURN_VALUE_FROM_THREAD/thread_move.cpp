#include <iostream>
#include <thread>
#include <future>
#include <vector>
#include <chrono>

using namespace std;

// another simple function

int square(int x)
{
    return x * x;
}

int main()
{
    packaged_task<int(int)> taskSquare(square);
    future<int> futureSquare = taskSquare.get_future();

    thread t1(move(taskSquare), 7);

    cout << "square via thread=" << futureSquare.get() << "\n";
    t1.join();
    cout << "\n";
    return 0;
}