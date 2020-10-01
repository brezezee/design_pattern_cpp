#include <iostream>
#include <cstdio>

using namespace std;

class Singleton {
public:
    static Singleton& getInstance() {
        static Singleton instance;
        return instance;
    }
protected:
    Singleton() = default;
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;
};


int main() {
    Singleton& inst1 = Singleton::getInstance();
    cout << "address: " << &inst1 << endl;

    Singleton& inst2 = Singleton::getInstance();
    cout << "address: " << &inst2 << endl;

    getchar();
    return 0;
}
