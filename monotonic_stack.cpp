#include<iostream>
#include<vector>
#include<stack>

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
};

int main() {
    Solution solution;
    // 739. 每日温度
    // vector<int> temperatures = {73,74,75,71,69,72,76,73};
    // vector<int> res = solution.dailyTemperatures(temperatures);
}