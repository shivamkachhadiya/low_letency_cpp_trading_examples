#include <iostream>

using namespace std;
int main()
{
    int bestbid = 101;
    int bestask = 103;

    auto spread = [&]
    {
        return bestask - bestbid;
    };

    // now change best bid;
    bestbid = 102;
    cout << spread(); // lambda function does not accepts parameter
    return 0;
}