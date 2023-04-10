#include<iostream>
#include<vector>
#include<stack>
#include<unordered_map>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

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

    // 84. 柱状图中最大的矩形
    // // 法二：单调栈
    // int largestRectangleArea(vector<int>& heights) {
    //     stack<int> st;
    //     int res = 0;
    //     // 原数组头、尾部加0，这一点要注意
    //     heights.insert(heights.begin(), 0);
    //     heights.push_back(0);
    //     for (int i = 0; i < heights.size(); i++) {
    //         if (st.empty() || heights[i] > heights[st.top()]) {
    //             st.push(i);
    //         } else if (heights[i] == heights[st.top()]) {
    //             st.pop();
    //             st.push(i);
    //         } else {
    //             while (!st.empty() && heights[i] < heights[st.top()]) {
    //                 int right = i;
    //                 int highest = heights[st.top()];
    //                 st.pop();
    //                 if (!st.empty()) {
    //                     int left = st.top();
    //                     res = max(res, highest * (right - left -1));
    //                 }
    //             }
    //             st.push(i);
    //         }
    //     }
    //     return res;
    // }
    //
    // int largestRectangleArea(vector<int>& heights) {
    //     // 法一：双指针法。找到每一列左右比自己小的第一列 【有参考】
    //     vector<int> minLeftIndex(heights.size());
    //     vector<int> minRightIndex(heights.size());
    //     int size = heights.size();
    //
    //     // 记录每个柱子 左边第一个小于该柱子的下标
    //     minLeftIndex[0] = -1; // 注意这里初始化，防止下面while死循环
    //     for (int i = 1; i < size; i++) {
    //         int t = i - 1;
    //         // 这里不是用if，而是不断向左寻找的过程
    //         while (t >= 0 && heights[t] >= heights[i]) t = minLeftIndex[t];
    //         minLeftIndex[i] = t;
    //     }
    //     // 记录每个柱子 右边第一个小于该柱子的下标
    //     minRightIndex[size - 1] = size; // 注意这里初始化，防止下面while死循环
    //     for (int i = size - 2; i >= 0; i--) {
    //         int t = i + 1;
    //         // 这里不是用if，而是不断向右寻找的过程
    //         while (t < size && heights[t] >= heights[i]) t = minRightIndex[t];
    //         minRightIndex[i] = t;
    //     }
    //     // 求和
    //     int result = 0;
    //     for (int i = 0; i < size; i++) {
    //         int sum = heights[i] * (minRightIndex[i] - minLeftIndex[i] - 1);
    //         result = max(sum, result);
    //     }
    //     return result;
    // }

    // 1019. 链表中的下一个更大节点
    // vector<int> nextLargerNodes(ListNode* head) {
    //     vector<int> nodes, res;
    //     while(head) {
    //         nodes.push_back(head->val);
    //         head = head->next;
    //     }
    //     res.resize(nodes.size(), 0);
    //     stack<int> st;
    //     for (int i = 0; i < nodes.size(); i++) {
    //         if (st.empty() || nodes[i] <= nodes[st.top()]) {
    //             st.push(i);
    //         } else {
    //             while (!st.empty() && nodes[i] > nodes[st.top()]) {
    //                 res[st.top()] = nodes[i];
    //                 st.pop();
    //             }
    //             st.push(i);
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

    // 503. 下一个更大元素 II
    // vector<int> nums = {1,2,1};
    // vector<int> res = solution.nextGreaterElements(nums);
    // for (int a : res) {
    //     cout<<a<<" ";
    // }

    // 42. 接雨水
    // vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    // cout<<solution.trap(height);

    // 84. 柱状图中最大的矩形
    // vector<int> heights = {2,4};
    // cout<<solution.largestRectangleArea(heights);
}