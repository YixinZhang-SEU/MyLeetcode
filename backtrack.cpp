#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    // 77. 组合
    // vector<vector<int> > res;
    // vector<int> tmp;
    // vector<vector<int> > combine(int n, int k) {
    //     backtracking(n, k, 1);
    //     return res;
    // }
    // void backtracking(int n, int k, int st_idx) {
    //     if (tmp.size() == k) {
    //         res.push_back(tmp);
    //         return;
    //     }
    //     for (int i = st_idx; i <=  n-(k-tmp.size())+1; i++) {
    //         tmp.push_back(i);
    //         backtracking(n, k, i+1);
    //         tmp.pop_back();
    //     }
    // }
};

int main() {
    Solution solution;

    // 77. 组合
    // vector<vector<int> > res = solution.combine(4, 2);
    // for (vector<int> a : res) {
    //     for (int b : a) {
    //         cout<<b<<" ";
    //     }
    //     cout<<endl;
    // }
}