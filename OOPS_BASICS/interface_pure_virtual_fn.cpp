#include <iostream>
using namespace std;

class strategy
{
public:
    virtual void onprice(int price) = 0;
    virtual ~strategy() = default;
};

class momentum : public strategy
{
public:
    void onprice(int price) override
    {
        cout << "momentum stratefy at=" << price << endl;
    }
};

int main()
{
    strategy *s = new momentum();
    s->onprice(00);
    delete s;
}