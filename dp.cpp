#include<iostream>
#include<vector>
#include<string>
#include<unordered_set>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

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

    // 198. 打家劫舍
    // int rob(vector<int>& nums) {
    //     vector<int> dp(nums.size(), 0);
    //     dp[0] = nums[0];
    //     if (nums.size() == 1) {
    //         return dp[0];
    //     }
    //     dp[1] = max(nums[0], nums[1]);
    //     for (int i = 2; i < nums.size(); i++) {
    //         dp[i] = max(dp[i-1], dp[i-2]+nums[i]);
    //     }
    //     return dp[nums.size()-1];
    // }

    // 213. 打家劫舍 II
    // int rob(vector<int>& nums) {
    //     if (nums.size() == 1) {
    //         return (nums[0]);
    //     }
    //     int res1 = robDP(nums, 0, nums.size()-2);
    //     int res2 = robDP(nums, 1, nums.size()-1);
    //     return max(res1, res2);
    // }
    // int robDP(vector<int>& nums, int start, int end) {
    //     if (start == end) {
    //         return nums[start];
    //     }
    //     vector<int> dp(nums.size(), 0);
    //     dp[start] = nums[start];
    //     dp[start+1] = max(dp[start], nums[start+1]);
    //     for (int i = start+2; i <= end; i++) {
    //         dp[i] = max(dp[i-1], dp[i-2]+nums[i]);
    //     }
    //     return dp[end];
    // }

    // 337. 打家劫舍 III （树形dp）（一刷参考）
    // int rob(TreeNode* root) {
    //     vector<int> dp = robDP(root);
    //     return max(dp[0], dp[1]);
    // }
    // vector<int> robDP(TreeNode* node) {
    //     if (node == nullptr) {
    //         return {0, 0};
    //     }
    //     vector<int> left = robDP(node->left);
    //     vector<int> right = robDP(node->right);
    //     int l = max(left[0], left[1]) + max(right[0], right[1]);
    //     int r = node->val + left[0] +right[0];
    //     return {l, r};
    // }

    // 121. 买卖股票的最佳时机
    // 法一：贪心
    // int maxProfit(vector<int>& prices) {
    //     int profit = 0;
    //     int min = prices[0];
    //     for (int i = 1; i < prices.size(); i++) {
    //         if (prices[i] < min) {
    //             min = prices[i];
    //         }
    //         else {
    //             profit = max(profit, prices[i]-min);
    //         }
    //     }
    //     return profit;
    // }
    // 法二：动态规划（有参考）
    // int maxProfit(vector<int>& prices) {
    //     vector<vector<int> > dp(prices.size(), vector<int>(2, 0));
    //     dp[0][0] = -prices[0];
    //     dp[0][1] = 0;
    //     for (int i = 1; i < prices.size(); i++) {
    //         dp[i][0] = max(dp[i-1][0], -prices[i]);
    //         dp[i][1] = max(dp[i-1][1], dp[i-1][0] + prices[i]);
    //     }
    //     return dp[prices.size()-1][1];
    // }

    // 122. 买卖股票的最佳时机 II
    // 法一：贪心（做过了）
    // 法二：动态规划（二维数组）
    // int maxProfit(vector<int>& prices) {
    //     vector<vector<int> > dp(prices.size(), vector<int>(2, 0));
    //     dp[0][0] = -prices[0];
    //     dp[0][1] = 0;
    //     for (int i = 1; i < prices.size(); i++) {
    //         dp[i][0] = max(dp[i-1][0], dp[i-1][1]-prices[i]);
    //         dp[i][1] = max(dp[i-1][1], dp[i-1][0] + prices[i]);
    //     }
    //     return dp[prices.size()-1][1];
    // }
    // 法三：动态规划（一维滚动数组）
    // int maxProfit(vector<int>& prices) {
    //     vector<vector<int> > dp(2, vector<int>(2, 0));
    //     dp[0][0] = -prices[0];
    //     dp[0][1] = 0;
    //     for (int i = 1; i < prices.size(); i++) {
    //         dp[i%2][0] = max(dp[(i-1)%2][0], dp[(i-1)%2][1]-prices[i]);
    //         dp[i%2][1] = max(dp[(i-1)%2][1], dp[(i-1)%2][0] + prices[i]);
    //     }
    //     return dp[(prices.size()-1)%2][1];
    // }

    // 123. 买卖股票的最佳时机 III
    // int maxProfit(vector<int>& prices) {
    //     vector<vector<int> > dp(prices.size(), vector<int>(5, 0));
    //     dp[0][1] = -prices[0];
    //     dp[0][3] = -prices[0];
    //     for (int i = 1; i < prices.size(); i++) {
    //         dp[i][1] = max(dp[i-1][1], -prices[i]);
    //         dp[i][2] = max(dp[i-1][2], dp[i-1][1] + prices[i]);
    //         dp[i][3] = max(dp[i-1][3], dp[i-1][2] - prices[i]);
    //         dp[i][4] = max(dp[i-1][4], dp[i-1][3] + prices[i]);
    //     }
    //     return dp[prices.size()-1][4];
    // }

    // 188. 买卖股票的最佳时机 IV [会了会了会了会了会了会了]
    // int maxProfit(int k, vector<int>& prices) {
    //     int res;
    //     if (k >= prices.size()/2) {
    //         res = maxProfit2(prices);
    //     } else {
    //         res = maxProfit3(k, prices);
    //     }
    //     return res;
    // }
    // int maxProfit2(vector<int>& prices) {
    //     vector<vector<int> > dp(prices.size(), vector<int>(2, 0));
    //     dp[0][0] = -prices[0];
    //     dp[0][1] = 0;
    //     for (int i = 1; i < prices.size(); i++) {
    //         dp[i][0] = max(dp[i-1][0], dp[i-1][1]-prices[i]);
    //         dp[i][1] = max(dp[i-1][1], dp[i-1][0] + prices[i]);
    //     }
    //     return dp[prices.size()-1][1];
    // }
    // int maxProfit3(int k, vector<int>& prices) {
    //     vector<vector<int> > dp(prices.size(), vector<int>(k*2+1, 0));
    //     for (int i = 1; i <= k; i++) {
    //         dp[0][i*2-1] = -prices[0];
    //     }
    //     for (int i = 1; i < prices.size(); i++) {
    //         for (int j = 1; j <= k; j++) {
    //             dp[i][j*2-1] = max(dp[i-1][j*2-1], dp[i-1][j*2-2]-prices[i]);
    //             dp[i][j*2] = max(dp[i-1][j*2], dp[i-1][j*2-1] + prices[i]);
    //         }
    //     }
    //     return dp[prices.size()-1][k*2];
    // }

    // 309. 最佳买卖股票时机含冷冻期
    // int maxProfit(vector<int>& prices) {
    //     vector<vector<int> > dp(prices.size(), vector<int>(4, 0));
    //     dp[0][0] = -prices[0];
    //     for (int i = 1; i < prices.size(); i++) {
    //         dp[i][0] = max(dp[i-1][0], max(dp[i-1][1]-prices[i], dp[i-1][3]-prices[i]));
    //         dp[i][1] = max(dp[i-1][3], dp[i-1][1]);
    //         dp[i][2] = dp[i-1][0] + prices[i];
    //         dp[i][3] = dp[i-1][2];
    //     }
    //     // 注意不能只取不拥有的状态(即状态2)
    //     int len = prices.size();
    //     return max(dp[len-1][1], max(dp[len-1][2], dp[len-1][3]));
    // }

    // 714. 买卖股票的最佳时机含手续费
    // int maxProfit(vector<int>& prices, int fee) {
    //     vector<vector<int> > dp(prices.size(), vector<int>(2, 0));
    //     dp[0][0] = -prices[0];
    //     for (int i = 1; i < prices.size(); i++) {
    //         dp[i][0] = max(dp[i-1][0], dp[i-1][1]-prices[i]);
    //         dp[i][1] = max(dp[i-1][1], dp[i-1][0]+prices[i]-fee);
    //     }
    //     return dp[prices.size()-1][1];
    // }

    // 300. 最长递增子序列
    // int lengthOfLIS(vector<int>& nums) {
    //     vector<int> dp(nums.size(), 1);
    //     int res = 1;
    //     for (int i = 1; i < nums.size(); i++) {
    //         for (int j = 0; j < i; j++) {
    //             if (nums[i] > nums[j] ) {
    //                 dp[i] = max(dp[i], dp[j] + 1);
    //             }
    //             if (res < dp[i]) {
    //                 res = dp[i];
    //             }
    //         }
    //     }
    //     return res;
    // }

    // 674. 最长连续递增序列
    // int findLengthOfLCIS(vector<int>& nums) {
    //     // 动态规划
    //     // int res = 1;
    //     // vector<int> dp(nums.size(), 1);
    //     // for (int i = 1; i < nums.size(); i++) {
    //     //     if (nums[i] > nums[i-1]) {
    //     //         dp[i] = dp[i-1]+1;
    //     //     }
    //     //     res = max(res, dp[i]);
    //     // }
    //     // return res;
    //     // 直接遍历
    //     int count = 1, res = 1;
    //     for (int i = 1; i < nums.size(); i++) {
    //         if (nums[i] > nums[i-1]) {
    //             count++;
    //         } else {
    //             count = 1;
    //         }
    //         res = max(res, count);
    //     }
    //     return res;
    // }

    // 718. 最长重复子数组
    // int findLength(vector<int>& nums1, vector<int>& nums2) {
    //     int res = 0;
    //     vector<vector <int> > dp(nums1.size(), vector<int>(nums2.size(), 0));
    //     for (int i = 0; i < nums2.size(); i++) {
    //         if (nums1[0] == nums2[i]) {
    //             dp[0][i] = 1;
    //             res = 1;
    //         }
    //     }
    //     for (int i = 0; i < nums1.size(); i++) {
    //         if (nums2[0] == nums1[i]) {
    //             dp[i][0] = 1;
    //             res = 1;
    //         }
    //     }
    //     for (int i = 1; i < nums1.size(); i++) {
    //         for (int j = 1; j < nums2.size(); j++) {
    //             if (nums1[i] == nums2[j]) {
    //                 dp[i][j] = dp[i-1][j-1] + 1;
    //             }
    //             res = max(res, dp[i][j]);
    //         }
    //     }
    //     return res;
    // }

    // 1143. 最长公共子序列
    // int longestCommonSubsequence(string text1, string text2) {
    //     vector<vector<int> > dp(text1.size(), vector<int>(text2.size()));
    //     // 初始化
    //     dp[0][0] = (text1[0] == text2[0]);
    //     for (int i = 1; i < text2.size(); i++) {
    //         if (text2[i] == text1[0]) {
    //             dp[0][i] = 1;
    //         } else {
    //             dp[0][i] = dp[0][i-1];
    //         }
    //     }
    //     for (int i = 1; i < text1.size(); i++) {
    //         if (text1[i] == text2[0]) {
    //             dp[i][0] = 1;
    //         } else {
    //             dp[i][0] = dp[i-1][0];
    //         }
    //     }
    //     // dp
    //     for (int i = 1; i < text1.size(); i++) {
    //         for (int j = 1; j < text2.size(); j++) {
    //             if (text1[i] == text2[j]) {
    //                 dp[i][j] = dp[i-1][j-1] + 1;
    //             } else {
    //                 dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
    //             }
    //         }
    //     }
    //     return dp[text1.size()-1][text2.size()-1];
    // }

    // 1035. 不相交的线
    // int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
    //     vector<vector<int> > dp(nums1.size() + 1, vector<int>(nums2.size() + 1, 0));
    //     // size+1 的话就不用写那么多初始化
    //     // dp
    //     for (int i = 1; i <= nums1.size(); i++) {
    //         for (int j = 1; j <= nums2.size(); j++) {
    //             if (nums1[i-1] == nums2[j-1]) {
    //                 dp[i][j] = dp[i-1][j-1] + 1;
    //             } else {
    //                 dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
    //             }
    //         }
    //     }
    //     return dp[nums1.size()][nums2.size()];
    // }

    // 53. 最大子数组和
    // int maxSubArray(vector<int>& nums) {
    //     vector<int> dp(nums.size());
    //     dp[0] = nums[0];
    //     int res = dp[0];
    //     for (int i = 1; i < nums.size(); i++) {
    //         dp[i] = max(dp[i-1] + nums[i], nums[i]);
    //         if (dp[i] > res) {
    //             res = dp[i];
    //         }
    //     }
    //     return res;
    // }
}
;

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

    // 198. 打家劫舍
    // vector<int> nums = {2,7,9,3,1};
    // cout<<solution.rob(nums);

    // 213. 打家劫舍 II
    // vector<int> nums = {2,1,1,2};
    // cout<<solution.rob(nums);

    // 121. 买卖股票的最佳时机
    // vector<int> prices = {7,1,5,3,6,4};
    // cout<<solution.maxProfit(prices);

    // 122. 买卖股票的最佳时机 II
    // vector<int> prices = {7,1,5,3,6,4};
    // cout<<solution.maxProfit(prices);

    // 123. 买卖股票的最佳时机 III
    // vector<int> prices = {2,1,2,0,1};
    // cout<<solution.maxProfit(prices);

    // 188. 买卖股票的最佳时机 IV
    // vector<int> prices = {6,1,6,4,3,0,2};
    // int k = 1;
    // cout<<solution.maxProfit(k, prices);

    // 300. 最长递增子序列
    // vector<int> nums = {1,3,6,7,9,4,10,5,6};
    // cout<<solution.lengthOfLIS(nums);
}