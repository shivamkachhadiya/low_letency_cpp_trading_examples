#include <iostream>
#include <thread>
#include <future>
#include <vector>
#include <chrono>

using namespace std;

// normal function that return values
int add(int a, int b)
{
    return a + b;
}

// another simple function

int square(int x)
{
    return x * x;
}

// slow function to justify threading

int computesum(const vector<int> &data)
{
    cout << "compute sum computation started..." << endl;

    // simple long computation
    this_thread::sleep_for(chrono::seconds(2));

    int sum = 0;
    for (int x : data)
    {
        sum += x;
    }
    cout << "compute sum computaion finished...." << endl;
    return sum;
}

int main()
{
    // normal functin call
    int normalResult = add(2, 3);
    cout << "normal add result=" << normalResult << "\n\n";

    /*
  If Add is executed in a thread,
  its return value is LOST.
  Threads cannot return values directly.
    */

    // packaged task+future (no thread yet)

    // wrap add function
    packaged_task<int(int, int)> taskAdd(add);

    // get future connected to this task
    future<int> futureAdd = taskAdd.get_future();

    // execute task like a normal function
    taskAdd(10, 20);

    /*
      Key points:
      - taskAdd DOES NOT return value
      - result is stored internally
      - future retrieves it
    */

    // pakaged task with thread

    packaged_task<int(int)> taskSquare(square);
    future<int> futureSquare = taskSquare.get_future();

    thread t1(move(taskSquare), 7);

    cout << "square via thread=" << futureSquare.get() << "\n";
    t1.join();
    cout << "\n";

    //================================ slow function with thread
    vector<int> data{1, 2, 3, 4, 5};

    packaged_task<int(const vector<int> &)> taskComputeThread(computesum);
    future<int> futureComputeThread = taskComputeThread.get_future();

    cout << "[main] starting ComputeSum in background thread\n";

    thread t2(move(taskComputeThread), data);

    cout << "[main] main thread is free to do other work...\n";

    // future.get() blocks ONLY when result is needed
    int finalResult = futureComputeThread.get();

    cout << "[main] ComputeSum result = " << finalResult << "\n";

    t2.join();

    cout << "\n========== END ==========\n";
    return 0;
}
