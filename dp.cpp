#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    // 509. 斐波那契数
    // // 法一：递归
    // int fib(int n) {
    //     if (n == 0) {
    //         return 0;
    //     }
    //     if (n == 1) {
    //         return 1;
    //     }
    //     return fib(n-1) + fib(n-2);
    // }
    //
    // 法二：dp
    // int fib(int n) {
    //     if (n <= 1) {
    //         return n;
    //     }
    //     vector<int> dp(n+1);
    //     dp[0] = 0;
    //     dp[1] = 1;
    //     for (int i = 2; i <= n; i++) {
    //         dp[i] = dp[i-1] + dp[i-2];
    //     }
    //     return dp[n];
    // }

    // 70. 爬楼梯
    // int climbStairs(int n) {
    //     vector<int> dp(n+1);
    //     if (n <= 2) {
    //         return n;
    //     }
    //     dp[1] = 1;
    //     dp[2] = 2;
    //     for (int i = 3; i <= n; i++) {
    //         dp[i] = dp[i-1] + dp[i-2];
    //     }
    //     return dp[n];
    // }
};

int main() {
    Solution solution;
    // 509. 斐波那契数
    // cout<<solution.fib(5);
}