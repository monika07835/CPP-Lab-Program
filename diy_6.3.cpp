#include <iostream>
#include <stdexcept>
using namespace std;

class SafeArray {
    int *data;
    int size;
public:
    SafeArray(int n) : size(n) {
        data = new int[size];
        for (int i = 0; i < size; ++i) data[i] = 0;
    }
    SafeArray(const SafeArray &o) : size(o.size) {
        data = new int[size];
        for (int i = 0; i < size; ++i) data[i] = o.data[i];
    }
    ~SafeArray() { delete[] data; }
    int& operator[](int i) {
        if (i < 0 || i >= size) throw out_of_range("index out of range");
        return data[i];
    }
};

int main() {
    SafeArray a(5);
    try {
        a[2] = 42;
        cout << "a[2] = " << a[2] << endl;
        a[10] = 7;   // throws
    }
    catch (const out_of_range &e) {
        cout << "Error: " << e.what() << endl;
    }
    return 0;
}