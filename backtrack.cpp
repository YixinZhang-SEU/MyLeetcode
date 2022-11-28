#include<iostream>
#include<vector>
#include<stdlib.h>
#include<algorithm>
#include<string>

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

    // 39. 组合总和
    // vector<vector<int> > res;
    // vector<int> tmp;
    // vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    //     backtracing(candidates, target, 0, 0);
    //     return res;
    // }
    // void backtracing(vector<int>& candidates, int target, int idx, int sum) {
    //     if (sum > target) {
    //         return;
    //     }
    //     if (sum == target) {
    //         res.push_back(tmp);
    //         return;
    //     }
    //     for (int i = idx; i < candidates.size(); i++) {
    //         sum += candidates[i];
    //         tmp.push_back(candidates[i]);
    //         backtracing(candidates, target, i, sum);
    //         sum -= candidates[i];
    //         tmp.pop_back();
    //     }
    // }

    // 40. 组合总和 II
    // vector<vector<int> > res;
    // vector<int> tmp;
    // vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    //     sort(candidates.begin(), candidates.end());
    //     backtracing(candidates, target, 0, 0);
    //     return res;
    // }
    // void backtracing(vector<int>& candidates, int target, int idx, int sum) {
    //     if (sum > target) {
    //         return;
    //     }
    //     if (sum == target) {
    //         res.push_back(tmp);
    //         return;
    //     }
    //     for (int i = idx; i < candidates.size(); i++) {
    //         if (i > idx && candidates[i] == candidates[i-1]) {
    //             continue;
    //         }
    //         sum += candidates[i];
    //         tmp.push_back(candidates[i]);
    //         backtracing(candidates, target, i+1, sum);
    //         sum -= candidates[i];
    //         tmp.pop_back();
    //     }
    // }

    // 131. 分割回文串
    // vector<vector<bool> > is_palindrome;      // is_palindrome[i][j]表示字符串s从i到j闭区间切片是否回文
    // vector<vector<string> > res;
    // vector<string> tmp;
    // vector<vector<string>> partition(string s) {
    //     computePalindrome(s);
    //     backtracing(s, 0);
    //     return res;
    // }
    // // 计算回文
    // void computePalindrome(string s) {
    //     is_palindrome.resize(s.size(), vector<bool>(s.size(), false));
    //     for (int i = s.size()-1; i >= 0; i--) {
    //         for (int j = i; j < s.size(); j++) {
    //             if (i == j) {
    //                 is_palindrome[i][j] = true;
    //             } else if (j-i == 1) {
    //                 is_palindrome[i][j] = (s[i] == s[j]);
    //             } else {
    //                 is_palindrome[i][j] = (s[i] == s[j])&&is_palindrome[i+1][j-1];
    //             }
    //         }
    //     }
    //     return;
    // }
    // // 回溯
    // void backtracing(string s, int idx) {
    //     if (idx >= s.size()) {
    //         res.push_back(tmp);
    //         return;
    //     }
    //     for (int i = idx; i < s.size(); i++) {
    //         if (is_palindrome[idx][i]) {
    //             tmp.push_back(s.substr(idx, i-idx+1));
    //         } else {
    //             continue;
    //         }
    //         backtracing(s, i+1);
    //         tmp.pop_back();
    //     }
    // }

    // 93. 复原 IP 地址
    // vector<string> res;
    // vector<string> restoreIpAddresses(string s) {
    //     backtracing(s, 0, 0);
    //     return res;
    // }
    // void backtracing(string s, int idx, int count) {
    //     if (idx > s.size()) {
    //         return;
    //     }
    //     if (count == 3) {
    //         if (isValid(s, idx, s.size()-1)) {
    //             res.push_back(s);
    //         }
    //         return;
    //     }
    //     for (int i = idx; i < s.size(); i++) {
    //         if (isValid(s, idx, i)) {
    //             s.insert(s.begin()+i+1, '.');
    //             count++;
    //             backtracing(s, i+2, count);
    //             count--;
    //             s.erase(s.begin()+i+1);
    //         } else {
    //             break;
    //         }
    //     }
    // }
    // bool isValid(string s, int st, int ed) {
    //     if (st > ed) {
    //         return false;
    //     }
    //     if (s[st] == '0' && st!=ed) {
    //         return false;
    //     }
    //     int num = 0;
    //     for (int i = st; i <= ed; i++) {
    //         if (s[i] > '9' || s[i] < '0') {
    //             return false;
    //         }
    //         num = num*10 + s[i]-'0';
    //         if (num > 255) {
    //             return false;
    //         }
    //     }
    //     return true;
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

    // 39. 组合总和
    // vector<int> candidates = {2};
    // vector<vector<int> > res = solution.combinationSum(candidates, 1);
    // for (vector<int> a : res) {
    //     for (int b : a) {
    //         cout<<b<<" ";
    //     }
    //     cout<<endl;
    // }

    // 40. 组合总和 II
    // vector<int> candidates = {10,1,2,7,6,1,5};
    // vector<vector<int> > res = solution.combinationSum2(candidates, 8);
    // for (vector<int> a : res) {
    //     for (int b : a) {
    //         cout<<b<<" ";
    //     }
    //     cout<<endl;
    // }

    // 131. 分割回文串
    // string s = "aaba";
    // vector<vector<string> > res = solution.partition(s);
    // for (vector<string> a : res) {
    //     for (string b : a) {
    //         cout<<b<<" ";
    //     }
    //     cout<<endl;
    // }

    // 93. 复原 IP 地址
    // string s = "25525511135";
    // vector<string> res = solution.restoreIpAddresses(s);
    // for (string s : res) {
    //     cout<<s<<endl;
    // }
}