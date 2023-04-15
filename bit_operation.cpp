#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    // 136. 只出现一次的数字
    // int singleNumber(vector<int>& nums) {
    //     int res = 0;
    //     for (int num : nums) {
    //         res ^= num;
    //     }
    //     return res;
    // }

    // 461. 汉明距离
    // int hammingDistance(int x, int y) {
    //     int num = x^y;
    //     int count = 0;
    //     while (num) {
    //         count += num&1;
    //         num>>=1;
    //     }
    //     return count;
    // }

    // 268. 丢失的数字
    // 主要思路是异或数组中的数和下标i，这样数组中存在的数都会被异或两次变成0，最后剩下来的就是数组里没有出现过的数，只异或了一次，与只出现一次的数的思路一样
    // int missingNumber(vector<int>& nums) {
    //     int res = 0;
    //     for (int i = 0; i < nums.size(); i++) {
    //         res = res^nums[i]^i;
    //     }
    //     res ^= nums.size();
    //     return res;
    // }

    // 260. 只出现一次的数字 III
    // vector<int> singleNumber(vector<int>& nums) {
    //     int diff = 0;
    //     for (int num : nums) {
    //         diff ^= num;
    //     }
    //     int bit = 1;
    //     while (!(diff & bit)) {
    //         bit <<= 1;
    //     }
    //     cout<<bit;
    //     int res1 = 0, res2 = 0;
    //     for (int num : nums) {
    //         if (num & bit) {
    //             res1 ^= num;
    //         } else {
    //             res2 ^= num;
    //         }
    //     }
    //     return{res1, res2};
    // }

    // 1017. 负二进制转换
    // string baseNeg2(int n) {
    //     if (n == 0) {
    //         return "0";
    //     }
    //     string res = "";
    //     while (n) {
    //         int tmp = n % (-2);
    //         int remainder = abs(n % (-2));
    //         res = (remainder == 0 ? '0' : '1') + res;
    //         n = (n - remainder) / (-2);
    //     }
    //     return res;
    // }
};

int main() {
    Solution solution;

    // 136. 只出现一次的数字
    // vector<int> nums = {4, 1, 2, 1, 2};
    // cout<<solution.singleNumber(nums);

    // 260. 只出现一次的数字 III
    // vector<int> nums = {1,2,1,3,2,5};
    // vector<int> res = solution.singleNumber(nums);
    // cout<<res[0]<<" "<<res[1];
}