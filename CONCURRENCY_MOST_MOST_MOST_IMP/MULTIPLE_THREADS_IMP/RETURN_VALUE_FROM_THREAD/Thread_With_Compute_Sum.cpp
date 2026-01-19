#include <iostream>
#include <thread>
#include <future>
#include <vector>
#include <chrono>

using namespace std;

int computesum(const vector<int> &data)
{
    cout << "compute sum computation started..." << endl;

    // simple long computation
    this_thread::sleep_for(chrono::seconds(5));

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
    vector<int> data{1, 2, 3, 4, 5};

    packaged_task<int(const vector<int> &)> taskComputeThread(computesum);

    future<int> futureComputeThread = taskComputeThread.get_future();

    cout << "[main] starting ComputeSum in background thread\n";

    thread th(move(taskComputeThread), data);

    cout << "[main] main thread is free to do other work...\n";

    // future.get() blocks ONLY when result is needed
    int finalResult = futureComputeThread.get();

    cout << "[main] ComputeSum result = " << finalResult << "\n";

    th.join();

    cout << "\n========== END ==========\n";
    return 0;
}
