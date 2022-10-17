#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
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
}