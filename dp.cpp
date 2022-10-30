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

    // 746. 使用最小花费爬楼梯
    // int minCostClimbingStairs(vector<int>& cost) {
    //     int size = cost.size();
    //     cost.push_back(0);
    //     vector<int> dp(cost.size()+1);
    //     dp[0] = cost[0];
    //     dp[1] = cost[1];
    //     for (int i = 2; i <= size; i++) {
    //         dp[i] = min(dp[i-1], dp[i-2]) + cost[i];
    //     }
    //     return dp[size];
    // }

    // 62. 不同路径
    // int uniquePaths(int m, int n) {
    //     vector<vector<int> >dp(m+1, vector<int>(n+1, 0));
    //     for (int i = 1; i <= m; i++) {
    //         dp[i][1] = 1;
    //     }
    //     for (int i = 1; i <= n; i++) {
    //         dp[1][i] = 1;
    //     }
    //     for (int i = 2; i <= m; i++) {
    //         for (int j = 2; j <= n; j++) {
    //             dp[i][j] = dp[i-1][j] + dp[i][j-1];
    //         }
    //     }
    //     return dp[m][n];
    // }
};

int main() {
    Solution solution;
    // 509. 斐波那契数
    // cout<<solution.fib(5);

    // 746. 使用最小花费爬楼梯
    // vector<int> cost = {1,100,1,1,1,100,1,1,100,1};
    // cout<<solution.minCostClimbingStairs(cost);

}