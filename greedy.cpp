#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
    // static  bool cmp(int a, int b) {
    //     return abs(a) > abs(b);
    // }
public:
    // 455. 分发饼干
    // int findContentChildren(vector<int>& g, vector<int>& s) {
    //     sort(g.begin(), g.end());
    //     sort(s.begin(), s.end());
    //     int idx = s.size()-1;
    //     int res = 0;
    //     for (int i = g.size()-1; i >= 0; i--) {
    //         if (idx >= 0 && s[idx] >= g[i]) {
    //             res++;
    //             idx--;
    //         }
    //     }
    //     return res;
    // }

    // 376. 摆动序列
    // int wiggleMaxLength(vector<int>& nums) {
    //     int count = 1;
    //     int pre = 0, cur = 0;
    //     for (int i = 0; i < nums.size() - 1; i++) {
    //         cur = nums[i+1] - nums[i];
    //         if ((cur > 0 && pre <= 0) || (cur < 0 && pre >= 0)) {
    //             count++;
    //             pre = cur;
    //         }
    //     }
    //     return count;
    // }

    // 53. 最大子数组和
    // int maxSubArray(vector<int>& nums) {
    //     int max = INT_MIN, sum = 0;
    //     for (int i = 0; i < nums.size(); i++) {
    //         sum += nums[i];
    //         if (sum > max) {
    //             max = sum;
    //         }
    //         if (sum < 0) {
    //             sum = 0;
    //         }
    //     }
    //     return max;
    // }

    // 122. 买卖股票的最佳时机 II
    // int maxProfit(vector<int>& prices) {
    //     int res = 0;
    //     int diff;
    //     for (int i = 0; i < prices.size()-1; i++) {
    //         diff = prices[i+1] - prices[i];
    //         if (diff > 0) {
    //             res += diff;
    //         }
    //     }
    //     return res;
    // }

    // 55. 跳跃游戏
    // bool canJump(vector<int>& nums) {
    //     int idx = 0;
    //     for (int i = 0; i <= idx; i++) {
    //         idx = max(i + nums[i], idx);
    //         if (idx >= nums.size() - 1) {
    //             return true;
    //         }
    //     }
    //     return false;
    // }

    // 45. 跳跃游戏 II
    // int jump(vector<int>& nums) {
    //     int res = 0;
    //     int cur = 0, next = 0;
    //     for (int i = 0; i < nums.size(); i++) {
    //         next = max(nums[i] + i, next);
    //         if (i == cur) {
    //             if (cur < nums.size()-1) {
    //                 res++;
    //                 cur = next;
    //                 if (next >= nums.size()) {
    //                     break;
    //                 }
    //             }
    //         }
    //     }
    //     return res;
    // }    

    // 1005. K 次取反后最大化的数组和
    // int largestSumAfterKNegations(vector<int>& nums, int k) {
    //     sort(nums.begin(), nums.end(), cmp);
    //     for (int i = 0; i < nums.size(); i++) {
    //         if (nums[i] < 0 && k > 0) {
    //             nums[i] = nums[i]*(-1);
    //             k--;
    //         }
    //     }
    //     if (k%2) {
    //         nums[nums.size()-1] = nums[nums.size()-1]*(-1);
    //     }
    //     int sum = 0;
    //     for (int a : nums) {
    //         sum += a;
    //     }
    //     return sum;
    // }

    // 134. 加油站
    // int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    //     int sum = 0;
    //     int total = 0;
    //     int idx = 0;
    //     for (int i = 0; i < gas.size(); i++) {
    //         sum += gas[i] - cost[i];
    //         total += gas[i] - cost[i];
    //         if (sum < 0) {
    //             idx = i+1;
    //             sum = 0;
    //         }
    //     }
    //     if (total < 0) {
    //         return -1;
    //     }
    //     return idx;
    // }

    // 135. 分发糖果
    // int candy(vector<int>& ratings) {
    //     if (ratings.size() == 1) {
    //         return 1;
    //     }
    //     vector<int> gets(ratings.size(), 1);
    //     for (int i = 0; i < ratings.size()-1; i++) {
    //         if (ratings[i+1] > ratings[i]) {
    //             gets[i+1] = gets[i] + 1;
    //         }
    //     }
    //     for (int i = ratings.size()-1; i > 0; i--) {
    //         if (ratings[i-1] > ratings[i] && gets[i-1] <= gets[i]) {
    //             gets[i-1] = gets[i] + 1;
    //         }
    //     }
    //     int sum = 0;
    //     for (int g : gets) {
    //         sum += g;
    //     }
    //     return sum;
    // }

    // 860. 柠檬水找零
    // bool lemonadeChange(vector<int>& bills) {
    //     int five = 0, ten = 0;
    //     for (int i = 0; i < bills.size(); i++) {
    //         if (bills[i] == 5) {
    //             five++;
    //         } else if (bills[i] == 10) {
    //             five--;
    //             if (five < 0) {
    //                 return false;
    //             }
    //             ten++;
    //         } else {
    //             if (ten > 0) {
    //                 ten--;
    //                 five--;
    //             } else {
    //                 five -= 3;
    //             }
    //             if (five < 0) {
    //                 return false;
    //             }
    //         }
    //     }
    //     return true;
    // }
};

int main() {
    Solution solution;

    // 455. 分发饼干
    // vector<int> g = {1, 2};
    // vector<int> s = {1, 2, 3};
    // int res = solution.findContentChildren(g, s);
    // cout<<res;

    // 376. 摆动序列
    // vector<int> nums = {1,2,3,4,5,6,7,8,9};
    // int res = solution.wiggleMaxLength(nums);
    // cout<<res;

    // 53. 最大子数组和
    // vector<int> vec = {-1};
    // int res = solution.maxSubArray(vec);
    // cout<<res;

    // 122. 买卖股票的最佳时机 II
    // vector<int> vec = {7,6,4,3,1};
    // cout<<solution.maxProfit(vec);

    // 45. 跳跃游戏 II
    // vector<int> vec = {2,3,0,1,4};
    // int res = solution.jump(vec);
    // cout<<res;

    // 1005. K 次取反后最大化的数组和
    // vector<int> nums = {2,-3,-1,5,-4};
    // cout<<solution.largestSumAfterKNegations(nums, 2);

    // 134. 加油站
    // vector<int> gas = {2,3,4};
    // vector<int> cost = {3,4,3};
    // cout<<solution.canCompleteCircuit(gas, cost);

    // 135. 分发糖果
    // vector<int> ratings = {1,3,4,5,2};
    // cout<<solution.candy(ratings);

    // 860. 柠檬水找零
    // vector<int> bills = {5,5,10,10,20};
    // cout<<solution.lemonadeChange(bills);
}