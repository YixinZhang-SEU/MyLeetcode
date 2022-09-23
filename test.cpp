#include<iostream>
#include<string>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
    // string s1 = "3";
    // string s2 = "-3";
    // int x1 = atoi(s2.c_str());
    // cout<<x1;
    vector<int> vec1 = {1, 2, 3}, vec2 = {3, 2, 1};
    reverse(vec2.begin(), vec2.end());
    if (vec1 == vec2) {
        cout<<"1";
    } else {
        cout<<"3";
    }
}