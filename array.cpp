#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    // 704.二分查找
    // int search(vector<int>& nums, int target) {
    //     int left = 0, right = nums.size(), middle;      //[left, right)左闭右开
    //     while (left < right) {
    //         middle = left + (right - left) / 2;
    //         if (nums[middle] == target) {
    //             return middle;
    //         } else if (nums[middle] < target) {
    //             left = middle + 1;
    //         } else {
    //             right = middle;
    //         }
    //     }
    //     return -1;
    // }

    // 27.移除元素
    // int removeElement(vector<int>& nums, int val) {
    //     if (nums.size() == 0){
    //         return 0;
    //     } 
    //     int left = 0, right = nums.size()-1;        // 双指针
    //     while (left <= right) {
    //         if (nums[left] == val) {
    //             while (nums[right] == val) {
    //                 right--;
    //                 if (right < 0 || right < left) {
    //                     return left;
    //                 }
    //             }
    //             // swap
    //             int temp = nums[left];
    //             nums[left] = nums[right];
    //             nums[right] = temp;
    //             left++;
    //         } else {
    //             left++;
    //         }
    //     }
    //     return left;
    // }

    // 977.有序数组的平方
    // vector<int> sortedSquares(vector<int>& nums) {
    //     vector<int> res(nums.size(), 0);
    //     // vector<int>::iterator it = res.begin();
    //     int left = 0, right = nums.size() - 1;
    //     for (int i = 0; i <= right; i++) {
    //         nums[i] = abs(nums[i]);     // 取绝对值
    //     }
    //     int idx = right;        // res的指针
    //     while (left <= right) {
    //         if (nums[left] >= nums[right]) {
    //             res[idx--] = nums[left] * nums[left];
    //             left++;
    //         } else {
    //             res[idx--] = nums[right] * nums[right];
    //             right--;
    //         }
    //     }
    //     return res;
    // }

    // 209.长度最小的子数组
    // int minSubArrayLen(int target, vector<int>& nums) {
    //     if (nums.size() == 1) {
    //         if (nums[0] < target) {
    //             return 0;
    //         } return 1;
    //     }
    //     // 长度大于1的情况
    //     int i = 0, j = 0, flag = 0;
    //     int sum = nums[0], lth = 0, min_lth = 1000000;
    //     while (i <= j && j < nums.size()) {
    //         if (sum < target) {
    //             j++;
    //             if (j < nums.size()) {
    //                 sum += nums[j];
    //             }
    //         } else {
    //             flag = 1;
    //             lth = j - i + 1;
    //             if (lth < min_lth) {
    //                 min_lth = lth;
    //             }
    //             sum -= nums[i++];
    //         }
    //     }
    //     if (flag) {
    //         return min_lth;
    //     } return 0;
    // }

    // 59.螺旋矩阵II
    // /*
    // 本题代码更简洁写法：四个for循环和其中的if条件完全可以合并起来，
    // 不需要存储左右边界值，因为这题方向是固定的，while()判定是否此方向下一个点已被赋值，
    // 如果赋值了就说明到达边界，直接固定一个坐标即可，不需要每次if
    // */
    // vector<vector<int>> generateMatrix(int n) {
    //     // 构建二维vector，以及为每一维赋长度
    //     vector<vector<int> > res(n);
    //     for (int i = 0; i < n; i++) {
    //         res[i].resize(n);
    //     }
    //     int i_u = 0, i_d = n-1, j_l = 0, j_r = n-1, num = 1, i = 0, j = 0;
    //     while (num <= n*n) {
    //         for (j = j_l; j <= j_r; j++) {
    //             res[i_u][j] = num++;
    //             if (num > n*n) {
    //                 return res;
    //             }
    //         }
    //         i_u++;
    //         for (i = i_u; i <= i_d; i++) {
    //             res[i][j_r] = num++;
    //             if (num > n*n) {
    //                 return res;
    //             }
    //         }
    //         j_r--;
    //         for (j = j_r; j >= j_l; j--) {
    //             res[i_d][j] = num++;
    //             if (num > n*n) {
    //                 return res;
    //             }
    //         }
    //         i_d--;
    //         for (i = i_d; i >= i_u; i--) {
    //             res[i][j_l] = num++;
    //             if (num > n*n) {
    //                 return res;
    //             }
    //         }
    //         j_l++;
    //     }
    //     return res;
    // }

    // 1365.有多少小于当前数字的数字
    // vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
    //     vector<int> vec = nums;
    //     sort(vec.begin(), vec.end());
    //     int hash[101];
    //     for (int i = vec.size()-1; i >= 0; i--) {
    //         hash[vec[i]] = i;
    //     }
    //     vector<int> res;
    //     for (int i = 0; i < nums.size(); i++) {
    //         res.push_back(hash[nums[i]]);
    //     }
    //     return res;
    // }
};

int main() {
    Solution solution;

    // 704.二分查找
    // vector<int> nums = {-1, 0, 3, 5, 9, 12};
    // cout<<solution.search(nums, 2)<<endl;

    // 27.移除元素
    // vector<int> nums = {2,2};
    // cout<<solution.removeElement(nums, 1)<<endl;
    // for (int i = 0; i < nums.size(); i++) {
    //     cout<<nums[i]<<", ";
    // }
    
    // 977.有序数组的平方
    // vector<int> nums = {-4, -1, 0, 3, 10};
    // vector<int> res = solution.sortedSquares(nums);
    // for (int i = 0; i <= nums.size() - 1; i++) {
    //     cout<<res[i]<<endl;
    // }
    // return 0;

    // 209.长度最小的子数组
    // vector<int> nums = {1,2,3,4,5};
    // cout<<solution.minSubArrayLen(11, nums)<<endl;

    // 59.螺旋矩阵
    // int n = 18;
    // vector<vector<int> > res = solution.generateMatrix(n);
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < n; j++) {
    //         cout<<res[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    // 1365.有多少小于当前数字的数字
}