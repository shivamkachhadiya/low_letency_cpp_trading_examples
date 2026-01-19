#include <iostream>
using namespace std;

class order
{
private:
    int quantity; // hidden data : private
public:
    order(int q) : quantity(q) {}
    void setQuantity(int q)
    {
        if (q > 0)
        {
            quantity = q;
        }
    }
    int getQuantity() const
    {
        return quantity; // use private member via function not directly
    }
};

int main()
{
    order o(10);
   
    o.setQuantity(20);
    cout << o.getQuantity() << endl;
    return 0;
}