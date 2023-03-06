#include<iostream>
#include<vector>
#include<stack>
#include<unordered_map>

using namespace std;

class Solution {
public:
    // 739. 每日温度
    // vector<int> dailyTemperatures(vector<int>& temperatures) {
    //     stack<int> st;
    //     vector<int> res(temperatures.size(), 0);
    //     for (int i = 0; i < temperatures.size(); i++) {
    //         if (st.empty() || temperatures[i] <= temperatures[st.top()]) {
    //             st.push(i);
    //         } else {
    //             while(!st.empty() && temperatures[st.top()] < temperatures[i]) {
    //                 int len = i - st.top();
    //                 res[st.top()] = len;
    //                 st.pop();
    //             }
    //             st.push(i);
    //         }
    //     }
    //     return res;
    // }

    // 496. 下一个更大元素 I
    // vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    //     // 哈希表 下标与元素映射
    //     unordered_map<int, int> umap;
    //     for (int i = 0; i < nums2.size(); i++) {
    //         umap[nums2[i]] = i;
    //     }
    //     // 单调栈
    //     stack<int> st;
    //     vector<int> vec2(nums2.size(), -1);
    //     for (int i = 0; i < nums2.size(); i++) {
    //         if (st.empty() || nums2[i] <= nums2[st.top()]) {
    //             st.push(i);
    //         } else {
    //             while (!st.empty() && nums2[i] > nums2[st.top()]) {
    //                 vec2[st.top()] = i;
    //                 st.pop();
    //             }
    //             st.push(i);
    //         }
    //     }
    //     // 填nums1
    //     vector<int> res(nums1.size(), -1);
    //     for (int i = 0; i < nums1.size(); i++) {
    //         int idx = vec2[umap[nums1[i]]];
    //         if (idx != -1) {
    //             res[i] = nums2[idx];
    //         }
    //     }
    //     return res;
    // }

    // 503. 下一个更大元素 II
    // 一个更好的方案是不改变原数组，而是在遍历的时候走两遍，i%nums.size()
    // vector<int> nextGreaterElements(vector<int>& nums) {
    //     vector<int> new_nums(nums.size()*2);
    //     for (int i = 0; i < nums.size(); i++) {
    //         new_nums[i] = nums[i];
    //         new_nums[i + nums.size()] = nums[i];
    //     }
    //     vector<int> temp(new_nums.size(), -1);
    //     stack<int> st;
    //     for (int i = 0; i < new_nums.size(); i++) {
    //         if (st.empty() || new_nums[i] <= new_nums[st.top()]) {
    //             st.push(i);
    //         } else {
    //             while (!st.empty() && new_nums[i] > new_nums[st.top()]) {
    //                 temp[st.top()] = new_nums[i];
    //                 st.pop();
    //             }
    //             st.push(i);
    //         }
    //     }
    //     return vector<int>(temp.begin(), temp.begin() + nums.size());
    // }

    // 42. 接雨水
    // int trap(vector<int>& height) {
    //     // 单调栈
    //     stack<int> st;
    //     int sum = 0;
    //     for (int i = 0; i < height.size(); i++) {
    //         if (st.empty() || height[i] < height[st.top()]) {
    //             st.push(i);
    //         } else if (height[i] == height[st.top()]) {
    //             st.pop();
    //             st.push(i);
    //         } else {
    //             while (!st.empty() && height[i] > height[st.top()]) {
    //                 int right = i;
    //                 int bottom = st.top();
    //                 st.pop();
    //                 if (st.empty()) {
    //                     st.push(i);
    //                     break;
    //                 }
    //                 int left = st.top();
    //                 sum += (min(height[left], height[right]) - height[bottom]) * (right - left - 1);
    //             }
    //             st.push(i);
    //         }
    //     }
    //     return sum;
    //     // 法二是双指针，算出每列左边最高和右边最高，取最小值，再减去自身，就是这一列（宽度为1）可以接的雨水
    // }
};

int main() {
    Solution solution;
    // 739. 每日温度
    // vector<int> temperatures = {73,74,75,71,69,72,76,73};
    // vector<int> res = solution.dailyTemperatures(temperatures);

    // 496. 下一个更大元素 I
    // vector<int> nums1 = {4,1,2}, nums2 = {1,3,4,2};
    // vector<int> res = solution.nextGreaterElement(nums1, nums2);
    // for (int a : res) {
    //     cout<<a<<" ";
    // }

    // 503. 下一个更大元素 II
    // vector<int> nums = {1,2,1};
    // vector<int> res = solution.nextGreaterElements(nums);
    // for (int a : res) {
    //     cout<<a<<" ";
    // }

    // 42. 接雨水
    // vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    // cout<<solution.trap(height);
}