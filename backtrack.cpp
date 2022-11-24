#include<iostream>
#include<vector>
#include<stdlib.h>

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

    // 216. 组合总和 III
    // vector<vector<int> > res;
    // vector<int> tmp;
    // vector<vector<int>> combinationSum3(int k, int n) {
    //     backtracing(n, k, 1, 0);
    //     return res;
    // }
    // void backtracing(int n, int k, int st_idx, int sum) {
    //     for (int i = st_idx; i <= 9-(k-tmp.size())+1; i++) {
    //         if (sum > n) {
    //             return;
    //         }
    //         if (tmp.size() == k) {
    //             if (sum == n) {
    //                 res.push_back(tmp);
    //                 return;
    //             }
    //         }
    //         sum += i;
    //         tmp.push_back(i);
    //         backtracing(n, k, i+1, sum);
    //         tmp.pop_back();
    //         sum -= i;    
    //     }
    //     return;
    // }

    // 17. 电话号码的字母组合
    // vector<vector<string> > alphas = {{}, {}, {"a","b","c"}, {"d", "e", "f"},  {"g", "h", "i"}, {"j", "k", "l"}, {"m", "n", "o"}, {"p", "q", "r", "s"}, {"t", "u", "v"}, {"w", "x", "y", "z"}};
    //
    // string tmp;
    // vector<string> res = {};
    // vector<string> letterCombinations(string digits) {
    //     int length = digits.length();
    //     if (!length) {
    //         return res;
    //     }
    //     int idx = 0;
    //     backtracing(length, idx, digits);
    //     return res;
    // }
    //
    // void backtracing(int length, int idx, string digits) {
    //     if (tmp.length() == length) {
    //         res.push_back(tmp);
    //         return;
    //     }
    //     for(string s : alphas[(int)digits[idx]-48]) {
    //         tmp += s;
    //         backtracing(length, idx+1, digits);
    //         tmp.erase(tmp.end()-1);
    //     }
    // }
}
;

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

    // 216. 组合总和 III
    // vector<vector<int> > res = solution.combinationSum3(4, 1);
    // for (vector<int> a : res) {
    //     for (int b : a) {
    //         cout<<b<<" ";
    //     }
    //     cout<<endl;
    // }

    // 17. 电话号码的字母组合
    // string digits = "2";
    // vector<string> res = solution.letterCombinations(digits);
    // for (string s : res) {
    //     cout<<s<<" ";
    // }
}