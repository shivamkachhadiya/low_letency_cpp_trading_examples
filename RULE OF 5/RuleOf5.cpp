#include <iostream>
#include <algorithm>
#include <utility>

using namespace std;

class Buffer
{
private:
    int *data;
    size_t size;

public:
    // constructor - allocate memory
    Buffer(size_t n)
        : data(new int[n]), size(n)
    {
        cout << "constructor allocate memory.." << size << "element" << endl;
    }

    ~Buffer()
    {
        delete[] data;
        cout << "destroyed..." << size << "elements.." << endl;
    }

    // copy constructor - deep copy
    Buffer(const Buffer &Other) : data(new int[Other.size]), size(Other.size)
    {
        copy(Other.data, Other.data + size, data);
        cout << "copied." << size << "elements";
    }
};