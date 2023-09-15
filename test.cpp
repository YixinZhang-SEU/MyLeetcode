#include<iostream>

using namespace std;

class A {
    static int a;
    int b;
};

int main() {
    cout << "sizeof(A):" << sizeof(A) << endl;
    A a;
    cout << "sizeof(a):" << sizeof(a) << endl;
}