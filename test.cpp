#include<iostream>
#include<string>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;

class A {
    static int a;
    int b;
};

int main() {
    int temp = 0;
    int i = 0;
    temp |= (1<<i);
    cout<<temp;
}