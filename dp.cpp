#include<iostream>
#include<vector>
#include<string>
#include<unordered_set>

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

    // 63. 不同路径 II
    // int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    //     vector<vector<int> > dp(obstacleGrid.size(), vector<int>(obstacleGrid[0].size(), 0));
    //     int m = obstacleGrid.size(), n = obstacleGrid[0].size();
    //     for (int i = 0; i < m; i++) {
    //         for (int j = 0; j < n; j++) {
    //             if (obstacleGrid[i][j] == 1) {
    //                 dp[i][j] = 0;
    //             }
    //         }
    //     }
    //     if (obstacleGrid[0][0] != 1) {
    //         dp[0][0] = 1;
    //     }
    //     for (int i = 1; i < m; i++) {
    //         if (obstacleGrid[i][0] != 1) {
    //             dp[i][0] = dp[i-1][0];
    //         }
    //     }
    //     for (int i = 1; i < n; i++) {
    //         if (obstacleGrid[0][i] != 1) {
    //             dp[0][i] = dp[0][i-1];
    //         }
    //     }
    //     for (int i = 1; i < m; i++) {
    //         for (int j = 1; j < n; j++) {
    //             if (obstacleGrid[i][j] != 1) {
    //                 dp[i][j] = dp[i-1][j] + dp[i][j-1];
    //             } 
    //         }
    //     }
    //     return dp[m-1][n-1];
    // }

    // 343. 整数拆分
    // int integerBreak(int n) {
    //     vector<int>dp(n+1, 0);
    //     dp[1] = 1;
    //     for (int i = 2; i <= n; i++) {
    //         for (int j = 1; j <= i/2; j++) {
    //             dp[i] = max(dp[i], j*max(i-j, dp[i-j]));
    //         }
    //     }
    //     return dp[n];
    // }

    // 96. 不同的二叉搜索树
    // int numTrees(int n) {
    //     vector<int>dp (n+1, 0);
    //     dp[0] = 1;
    //     dp[1] = 1;
    //     for (int i = 2; i <= n; i++) {
    //         for (int j = 1; j <= i; j++) {
    //             dp[i] += (dp[j-1] * dp[i-j]);
    //         }
    //     }
    //     return dp[n];
    // }

    // 416. 分割等和子集
    // bool canPartition(vector<int>& nums) {
    //     int sum = 0;
    //     for (int num : nums) {
    //         sum += num;
    //     }
    //     if (sum%2) {
    //         return false;
    //     }
    //     int target = sum/2;
    //     vector<int> dp(10001, 0);
    //     dp[0] = 0;
    //     for (int i = 0; i < nums.size(); i++) {
    //         for (int j = target; j >= nums[i]; j--) {
    //             dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
    //         }
    //     }
    //     if (dp[target] == target) {
    //         return true;
    //     }
    //     return false;
    // }

    // 1049. 最后一块石头的重量 II (转化成背包问题有难度，一刷有参考)
    // int lastStoneWeightII(vector<int>& stones) {
    //     int sum = 0;
    //     for (int stone : stones) {
    //         sum += stone;
    //     }
    //     int target = sum/2;
    //     vector<int> dp(sum+1, 0);
    //     dp[0] = 0;
    //     for (int i = 0; i < stones.size(); i++) {
    //         for (int j = target; j >= stones[i]; j--) {
    //             dp[j] = max(dp[j], dp[j-stones[i]] + stones[i]);
    //         }
    //     }
    //     return sum- dp[target]*2;
    // }

    // 494. 目标和
    // int findTargetSumWays(vector<int>& nums, int target) {
    //     int sum = 0;
    //     for (int a : nums) {
    //         sum += a;
    //     }
    //     if (abs(target) > sum || (target+sum)%2) {
    //         return 0;
    //     }
    //     int bag = (target+sum)/2;
    //     vector<int> dp(bag+1, 0);
    //     dp[0] = 1;
    //     for (int i = 0; i < nums.size(); i++) {
    //         for (int j = bag; j >= nums[i]; j--) {
    //             dp[j] += dp[j- nums[i]];
    //         }
    //     }
    //     return dp[bag];
    // }

    // 474. 一和零
    // int findMaxForm(vector<string>& strs, int m, int n) {
    //     // 得到0,1个数的数组
    //     vector<int> zero = {}, one = {};
    //     for (string s : strs) {
    //         int z = 0, o = 0;
    //         for (char a : s) {
    //             if(a == '0') {
    //                 z++;
    //             } else {
    //                 o++;
    //             }
    //         }
    //         zero.push_back(z);
    //         one.push_back(o);
    //     }
    //     // 二维背包
    //     vector<vector<int> > dp(m+1, vector<int> (n+1, 0));
    //     for (int i = 0; i < strs.size(); i++) {
    //         for (int j = m; j >= zero[i]; j--) {
    //             for (int k = n; k >= one[i]; k--) {
    //                 dp[j][k] = max(dp[j][k], dp[j-zero[i]][k-one[i]]+1);
    //             }
    //         }
    //     }
    //     return dp[m][n];
    // }

    // 518. 零钱兑换 II
    // int change(int amount, vector<int>& coins) {
    //     vector<int> dp(amount+1, 0);
    //     dp[0] = 1;
    //     for (int i = 0; i < coins.size(); i++) {
    //         for (int j = coins[i]; j <= amount; j++) {
    //             dp[j] += dp[j-coins[i]];
    //         }
    //     }
    //     return dp[amount];
    // }

    // 377. 组合总和 Ⅳ
    // int combinationSum4(vector<int>& nums, int target) {
    //     vector<int> dp(target+1, 0);
    //     dp[0] = 1;
    //     // 先遍历包的容量，再遍历物品
    //     for (int i = 0; i <= target; i++) {
    //         for (int j = 0; j < nums.size(); j++) {
    //             if (i - nums[j] >= 0) {
    //                 dp[i] += dp[i-nums[j]];
    //             }
    //         }
    //     }
    //     return dp[target];
    // }

    // 322. 零钱兑换
    // int coinChange(vector<int>& coins, int amount) {
    //     if (amount == 0) {
    //         return 0;
    //     }
    //     vector<int> dp(amount+1, INT_MAX);
    //     dp[0] = 0;
    //     for (int i = 0; i < coins.size(); i++) {
    //         for (int j = coins[i]; j <= amount; j++) {
    //             if (dp[j-coins[i]] != INT_MAX) {
    //                 dp[j] = min(dp[j], dp[j-coins[i]]+1);
    //             }
    //         }
    //     }
    //     if (dp[amount] == INT_MAX) {
    //         return -1;
    //     }
    //     return dp[amount];
    // }

    // 279. 完全平方数
    // int numSquares(int n) {
    //     vector<int> dp(n+1, INT_MAX);
    //     dp[0] = 0;
    //     for (int i = 1; i*i < n; i++) {
    //         for (int j = i*i; j <= n; j++) {
    //             dp[j] = min(dp[j], dp[j-i*i]+1);
    //         }
    //     }
    //     return dp[n];
    // }

    // 139. 单词拆分
    // bool wordBreak(string s, vector<string>& wordDict) {
    //     unordered_set<string> wordset(wordDict.begin(), wordDict.end());
    //     vector<bool> dp(s.size()+1, false);
    //     dp[0] = true;
    //     // 这里顺序很重要，因此要先遍历背包，再遍历物品
    //     for (int i = 1; i <= s.size(); i++) {
    //         for (int j = 0; j < i; j++) {
    //             if (wordset.find(s.substr(j, i-j)) != wordset.end() && dp[j]) {
    //                 dp[i] = true;
    //             }
    //         }
    //     }
    //     return dp[s.size()];
    // }
};

int main() {
    Solution solution;
    // 509. 斐波那契数
    // cout<<solution.fib(5);

    // 746. 使用最小花费爬楼梯
    // vector<int> cost = {1,100,1,1,1,100,1,1,100,1};
    // cout<<solution.minCostClimbingStairs(cost);

    // 63. 不同路径 II
    // vector<vector<int> > obs = {{0,1},{0,0}};
    // cout<<solution.uniquePathsWithObstacles(obs);

    // 343. 整数拆分
    // cout<<solution.integerBreak(10);

    // 96. 不同的二叉搜索树
    // cout<<solution.numTrees(3);

    // 416. 分割等和子集
    // vector<int> nums = {1,2,3,5};
    // cout<<solution.canPartition(nums);

    // 474. 一和零
    // vector<string> strs = {"10","0001","111001","1","0"};
    // int m = 5, n =3;
    // cout<<solution.findMaxForm(strs, m, n);

    // 518. 零钱兑换 II
    // vector<int> coins = {1, 2, 5};
    // int amount = 5;
    // cout<<solution.change(amount, coins);

    // 377. 组合总和 Ⅳ
    // vector<int> nums = {1,2,3};
    // int target = 4;
    // cout<<solution.combinationSum4(nums, target);

    // 322. 零钱兑换
    // vector<int> coins = {1};
    // int amount = 0;
    // cout<<solution.coinChange(coins, amount);

    // 279. 完全平方数
    // int n = 1;
    // cout<<solution.numSquares(n);

    // 139. 单词拆分
    // vector<string> dict = {"cats", "dog", "sand", "and", "cat"};
    // string s = "catsandog";
    // cout<<solution.wordBreak(s, dict);
}