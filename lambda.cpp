#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int price = 100;
    // capture by value
    auto f = [price]() // if [&price] by ref. it will change value
    {
        cout << "price is=>" << price << endl;
    };
    price = 300;
    f();
    return 0;
}