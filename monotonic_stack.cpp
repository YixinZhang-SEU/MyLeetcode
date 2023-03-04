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
}