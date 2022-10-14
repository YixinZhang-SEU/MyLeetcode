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
}