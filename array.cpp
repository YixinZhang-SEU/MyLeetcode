#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
// #include<bits/stdc++.h>

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

    // 941. 有效的山脉数组
    // bool validMountainArray(vector<int>& arr) {
    //     // 法一：从头到尾遍历法
    //     int top;
    //     for (int i = 0; i < arr.size()-1; i++) {
    //         if (arr[i] == arr[i+1]) {
    //             return false;
    //         }
    //         if (arr[i] > arr[i+1]) {
    //             top = i;
    //             break;
    //         }
    //     }
    //     if (!(top == arr.size()-1) && !(top == 0)) {
    //         for (int i = top; i < arr.size()-1; i++) {
    //             if (arr[i] <= arr[i+1]) {
    //                 return false;
    //             }
    //         }
    //     } else {
    //         return false;
    //     }
    //     return true;
    //
    //     // 法二：双指针法
    //     int left = 0, right = arr.size() - 1;
    //     while (left < arr.size() - 1 && arr[left] < arr[left + 1]) {
    //         left++;
    //     }
    //     while (right > 0 && arr[right] < arr[right - 1]) {
    //         right--;
    //     }
    //     if (left == right && left != 0 && right != arr.size() - 1) {
    //         return true;
    //     }
    //     return false;
    // }

    // 1207. 独一无二的出现次数
    // bool uniqueOccurrences(vector<int>& arr) {
    //     unordered_map<int, int> freq;
    //     unordered_set<int> freq_set;
    //     for (int num : arr) {
    //         freq[num]++;
    //     }
    //     for (unordered_map<int, int>::iterator it = freq.begin(); it != freq.end(); it++) {
    //         if (freq_set.find(it->second) == freq_set.end()) {
    //             freq_set.insert(it->second);
    //         } else {
    //             return false;
    //         }
    //     }
    //     return true;
    // }

    // 283. 移动零
    // void moveZeroes(vector<int>& nums) {
    //     int fast = 0, slow = 0;
    //     for (; fast < nums.size(); fast++) {
    //         if (nums[fast] != 0) {
    //             nums[slow++] = nums[fast];
    //         }
    //     }
    //     for (int i = slow; i < nums.size(); i++) {
    //         nums[i] = 0;
    //     }
    //     return;
    // }

    // 189. 轮转数组
    // void rotate(vector<int>& nums, int k) {
    //     int len = nums.size();
    //     k = k % len;
    //     if (k == 0) {
    //         return;
    //     }
    //     reverse(nums.begin(), nums.begin() + len - k);
    //     reverse(nums.begin() + len - k, nums.end());
    //     reverse(nums.begin(), nums.end());
    //     return;
    // }

    // 724. 寻找数组的中心下标
    // int pivotIndex(vector<int>& nums) {
    //     // 这题关键是计算左右时，如果在下标0或size-1处没法计算。两边都可以加上自身
    //     int sum = 0;
    //     for (int num : nums) {
    //         sum += num;
    //     }
    //     int left = 0, right = 0;
    //     for (int i = 0; i < nums.size(); i++) {
    //         left += nums[i];
    //         right = sum - left + nums[i];
    //         if (left == right) {
    //             return i;
    //         }
    //     }
    //     return -1;
    // }

    // 34. 在排序数组中查找元素的第一个和最后一个位置
    // // 本题要点：首先求出 >=target 的最左边数下标； 再求出 >=target + 1 的最左边数下标
    // vector<int> searchRange(vector<int>& nums, int target) {
    //     int left = binarySearch(nums, target);
    //     int right = binarySearch(nums, target + 1);
    //     if (left == nums.size() || nums[left] != target) {
    //         return {-1, -1};
    //     }
    //     return {left, right - 1};
    // }
    // //
    // int binarySearch(vector<int>& nums, int target) {
    //     int left = 0, right = nums.size() - 1;
    //     while (left <= right) {
    //         int mid = left + ((right - left)/2);
    //         if (nums[mid] >= target) {
    //             right = mid - 1;
    //         } else {
    //             left = mid + 1;
    //         }
    //     }
    //     return left;
    // }

    // 922. 按奇偶排序数组 II
    // vector<int> sortArrayByParityII(vector<int>& nums) {
    //     vector<int> res(nums.size());
    //     int even = 0, odd = 1;
    //     for (int i = 0; i < nums.size(); i++) {
    //         if (nums[i] % 2) {
    //             res[odd] = nums[i];
    //             odd += 2;
    //         } else {
    //             res[even] = nums[i];
    //             even += 2;
    //         }
    //     }
    //     return res;
    // }

    // 169. 多数元素
    // // 法一：排序
    // int majorityElement(vector<int>& nums) {
    //     sort(nums.begin(), nums.end());
    //     return nums[nums.size() / 2];
    // }
    // // 法二：摩尔投票法
    // int majorityElement(vector<int>& nums) {
    //     int res, count = 0;
    //     for (int num : nums) {
    //         if (count == 0) {
    //             res = num;
    //             count++;
    //         } else if (num == res) {
    //             count++;
    //         } else {
    //             count--;
    //         }
    //     }
    //     return res;
    // }

    // 268. 丢失的数字
    // int missingNumber(vector<int>& nums) {
    //     int n = nums.size();
    //     int sum = (1 + n) * n / 2;
    //     for (int num : nums) {
    //         sum -= num;
    //     }
    //     return sum;
    // }

    // 1053. 交换一次的先前排列
    // vector<int> prevPermOpt1(vector<int>& arr) {
        // 复杂度高得要死
        // int len = arr.size();
        // vector<int> count(len, -1);
        // for (int i = 0; i < len; i++) {
        //     int flag = 0;
        //     for (int j = len - 1; j > i; j--) {
        //         if (arr[j] < arr[i]) {
        //             if (!flag || arr[j] == arr[j + 1]) {
        //                 count[i] = j;
        //                 flag = 1;
        //             } else {
        //                 break;
        //             }
        //         }
        //     }
        // }
        // for (int i = len - 1; i >= 0; i--) {
        //     if (count[i] != -1) {
        //         swap(arr[i], arr[count[i]]);
        //         break;
        //     }
        // }
        // return arr;
        // // 另一种方法：从后往前找小于a[i]的最大的数a[j]，有多个相同的a[i]，就取最左边的
    //     int len = arr.size();
    //     for (int i = len - 2; i >= 0; i--) {
    //         if (arr[i] > arr[i + 1]) {
    //             int j = i + 1;
    //             while (j + 1 < len && arr[j + 1] < arr[i]) {
    //                 j++;
    //             }
    //             while (arr[j - 1] == arr[j]) {
    //                 j--;
    //             }
    //             swap(arr[i], arr[j]);
    //             return arr;
    //         }
    //     }
    //     return arr;
    // }

    // 2427. 公因子的数目
    // int commonFactors(int a, int b) {
    //     // 法一：暴力
    //     int count = 0;
    //     for (int i = 1; i <= (a > b ? b : a); i++) {
    //         if (a%i == 0 && b%i == 0) {
    //             count++;
    //         }
    //     }
    //     return count;
    //     // 法二：枚举到最大公约数
    //     int g = __gcd(a, b);
    //     int count = 0;
    //     for (int i = 1; i * i <= g; i++) {
    //         if (g % i == 0) {
    //             count++;
    //             if (i * i != g) {
    //                 count++;
    //             }
    //         }
    //     }
    //     return count;
    // }

    // 1040. 移动石子直到连续 II （有参考）
    // vector<int> numMovesStonesII(vector<int>& stones) {
    //     int n = stones.size();
    //     sort(stones.begin(), stones.end());
    //     int num1 = stones[n - 1] - stones[1] - n + 2;
    //     int num2 = stones[n - 2] - stones[0] - n + 2;
    //     int max_move = max(num1, num2);
    //     if (num1 == 0 || num2 == 0) {
    //         return {min(2, max_move), max_move};
    //     }
    //     int count = 0, left = 0;
    //     for (int right = 0; right < n; right++) {
    //         while (stones[right] - stones[left] + 1 > n) {
    //             left++;
    //         }
    //         count = max(count, right - left + 1);
    //     }
    //     return {n - count, max_move};
    // }

    // 75. 颜色分类
    // void sortColors(vector<int>& nums) {
    //     int zero = 0, two = nums.size() - 1;
    //     for (int i = 0; i <= two; i++) {
    //         if (nums[i] == 0) {
    //             swap(nums[i], nums[zero++]);
    //         } else if (nums[i] == 2) {
    //             swap(nums[i--], nums[two--]);
    //         }
    //     }
    // }

    // 31. 下一个排列
    // void nextPermutation(vector<int>& nums) {
    //     for (int i = nums.size() - 1; i >= 0; i--) {
    //         for (int j = nums.size() - 1; j > i; j--) {
    //             if (nums[j] > nums[i]) {
    //                 swap(nums[i], nums[j]);
    //                 sort(nums.begin() + i + 1, nums.end());
    //                 return;
    //             }
    //         }
    //     }
    //     reverse(nums.begin(), nums.end());
    //     return;
    // }

    // 2404. 出现最频繁的偶数元素
    // int mostFrequentEven(vector<int>& nums) {
    //     sort(nums.begin(), nums.end());
    //     if (nums.size() == 0) {
    //         return -1;
    //     }
    //     int maxeven = -1;
    //     int maxcnt = 0;
    //     int cnt = 0;
    //     if (nums[0] % 2 == 0) {
    //         cnt = 1;
    //         maxcnt = 1;
    //         maxeven = nums[0];
    //     }
    //     for (int i = 1; i < nums.size(); i++) {
    //         if (nums[i] % 2 == 0) {
    //             if (nums[i] == nums[i - 1]) {
    //                 cnt++;
    //             } else {
    //                 cnt = 1;
    //             }
    //             //
    //             if (cnt > maxcnt) {
    //                 maxcnt = cnt;
    //                 maxeven = nums[i];
    //             }
    //         }
    //     }
    //     return maxeven;
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

    // 941. 有效的山脉数组
    // vector<int> arr = {3,7,6,4,3,0,1,0};
    // cout<<solution.validMountainArray(arr);

    // 283. 移动零
    // vector<int> nums = {0,1,0,3,12};
    // solution.moveZeroes(nums);

    // 189. 轮转数组
    // vector<int> nums = {1, 2, 3};
    // int k = 2;
    // solution.rotate(nums, k);
    // for (int a : nums) {
    //     cout<<a<<" ";
    // }

    // 34. 在排序数组中查找元素的第一个和最后一个位置
    // vector<int> nums = {5,7,7,8,8,10};
    // int target = 8;
    // cout<<solution.searchRange(nums, target)[0]<<" "<<solution.searchRange(nums, target)[1];

    // 1053. 交换一次的先前排列
    // vector<int> arr = {3,1,1,3};
    // vector<int> res = solution.prevPermOpt1(arr);
    // for (int a : res) {
    //     cout<<a<<" ";
    // }

    // 2404. 出现最频繁的偶数元素
    // vector<int> nums = {8154,9139,8194,3346,5450,9190,133,8239,4606,8671,8412,6290};
    // cout<<solution.mostFrequentEven(nums);
}