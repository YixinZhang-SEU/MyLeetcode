#include<iostream>
#include<stack>
#include<queue>
#include<algorithm>
#include<unordered_map>
using namespace std;

// 232. 用栈实现队列
// class MyQueue {
// public:
//     stack<int> sIn, sOut;
//     MyQueue() {
//
//     }
//  
//     void push(int x) {
//         sIn.push(x);
//     }
//  
//     int pop() {
//         if (sOut.empty()) {
//             while (!sIn.empty()) {
//                 sOut.push(sIn.top());
//                 sIn.pop();
//             }
//         }
//         int res = sOut.top();
//         sOut.pop();
//         return res;
//     }
//   
//     int peek() {
//         int res = this->pop();
//         sOut.push(res);
//         return res;
//     }
//    
//     bool empty() {
//         if (sIn.empty() && sOut.empty()) {
//             return true;
//         }
//         return false;
//     }
// };

// 225. 用队列实现栈
// class MyStack {
//     queue<int> q1, q2;
// public:
//     MyStack() {
// //
//     }
// //
//     void push(int x) {
//         q1.push(x);
//     }
// //
//     int pop() {
//         int lth = q1.size();
//         lth--;
//         while(lth--) {
//             q2.push(q1.front());
//             q1.pop();
//         }
//         int res = q1.front();
//         q1.pop();
//         q1 = q2;
//         while (!q2.empty()) {
//             q2.pop();
//         }
//         return res;
//     }
// //
//     int top() {
//         return q1.back();
//     }
// //
//     bool empty() {
//         if (q1.empty()) {
//             return true;
//         }
//         return false;
//     }
// };

class Solution {
private:
    // 单调递减队列
    // class MyQueue {
    // public:
    //     deque<int> q;
    //     // push时查看需要push的元素是否大于队尾（比较小）的元素，要把所有小于待插入数值的元素都从队尾弹出，最后在队尾插入待插元素
    //     void push(int value) {
    //         while (!q.empty() && q.back() < value) {
    //             q.pop_back();
    //         }
    //         q.push_back(value);
    //     }
    //     // pop时查看需要pop的元素是否等于队头（最大）元素的值，是的话弹出队头元素，否则不需要任何操作。
    //     void pop(int value) {
    //         if (!q.empty() && q.front() == value) {
    //             q.pop_front();
    //         }
    //     }
    //     // front出来的就是最大的元素
    //     int front() {
    //         return q.front();
    //     }
    // };

public:
    class mycomparision {
        public:
        // 小顶堆，注意是 ">"
        bool operator()(const pair<int, int>& lhs, const pair<int, int>& rhs) {
            return lhs.second > rhs.second;
        }
    };

    // 20. 有效的括号
    // bool isValid(string s) {
    //     // // 法一
    //     // if (s.size() == 0) {
    //     //     return true;
    //     // }
    //     // stack<char> st;
    //     // for (int i = 0; i < s.size(); i++) {
    //     //     switch(s[i]) {
    //     //         case '(': case '[': case '{': {
    //     //             st.push(s[i]);
    //     //             break;
    //     //         }
    //     //         case ')': {
    //     //             if (st.empty()) {
    //     //                 return false;
    //     //             }
    //     //             char c = st.top();
    //     //             if (c != '(') {
    //     //                 return false;
    //     //             } 
    //     //             st.pop();
    //     //             break;
    //     //         }
    //     //         case ']': {
    //     //             if (st.empty()) {
    //     //                 return false;
    //     //             }
    //     //             char c = st.top();
    //     //             if (c != '[') {
    //     //                 return false;
    //     //             } 
    //     //             st.pop();
    //     //             break;
    //     //         }
    //     //         case '}': {
    //     //             if (st.empty()) {
    //     //                 return false;
    //     //             }
    //     //             char c = st.top();
    //     //             if (c != '{') {
    //     //                 return false;
    //     //             } 
    //     //             st.pop();
    //     //             break;
    //     //         }
    //     //     }
    //     // }
    //     // return st.empty();
    //     //
    //     // 法二
    //     if (s.size() % 2) {
    //         return false;
    //     }
    //     stack<char> st;
    //     for (int i = 0; i < s.size(); i++) {
    //         if (s[i] == '(') {
    //             st.push(')');
    //         } else if (s[i] == '{') {
    //             st.push('}');
    //         } else if (s[i] == '[') {
    //             st.push(']');
    //         } else if (st.empty() || s[i] != st.top()) {
    //             return false;
    //         } else {
    //             st.pop();
    //         }
    //     }
    //     return st.empty();
    // }

    // 1047. 删除字符串中的所有相邻重复项
    // string removeDuplicates(string s) {
    //     stack<char> st;
    //     for (int i = 0; i < s.size(); i++) {
    //         if (st.empty()) {
    //             st.push(s[i]);
    //         } else {
    //             if (s[i] == st.top()) {
    //                 st.pop();
    //             } else {
    //                 st.push(s[i]);
    //             }
    //         }
    //     }
    //     stack<char> tmp;
    //     while (!st.empty()) {
    //         tmp.push(st.top());
    //         st.pop();
    //     }
    //     string res;
    //     while (!tmp.empty()) {
    //         res.push_back(tmp.top());
    //         tmp.pop();
    //     }
    //     return res;
    // }

    // 150. 逆波兰表达式求值
    // int evalRPN(vector<string>& tokens) {
    //     stack<string> st;
    //     int op1, op2, tmp;
    //     for (string s : tokens) {
    //         if (s == "+") {
    //             op2 = atoi(st.top().c_str());
    //             st.pop();
    //             op1 = atoi(st.top().c_str());
    //             st.pop();
    //             tmp = op1 + op2;
    //             st.push(to_string(tmp));
    //         } else if (s == "-") {
    //             op2 = atoi(st.top().c_str());
    //             st.pop();
    //             op1 = atoi(st.top().c_str());
    //             st.pop();
    //             tmp = op1 - op2;
    //             st.push(to_string(tmp));
    //         } else if (s == "*") {
    //             op2 = atoi(st.top().c_str());
    //             st.pop();
    //             op1 = atoi(st.top().c_str());
    //             st.pop();
    //             tmp = op1 * op2;
    //             st.push(to_string(tmp));
    //         } else if (s == "/") {
    //             op2 = atoi(st.top().c_str());
    //             st.pop();
    //             op1 = atoi(st.top().c_str());
    //             st.pop();
    //             tmp = op1 / op2;
    //             st.push(to_string(tmp));
    //         } else {
    //             st.push(s);
    //         }
    //     }
    //     return atoi(st.top().c_str());
    // }

    // 239. 滑动窗口最大值（单调队列，一刷有参考）
    // vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    //     MyQueue q;
    //     vector<int> res;
    //     for (int i = 0; i < k; i++) {
    //         q.push(nums[i]);
    //     }
    //     res.push_back(q.front());
    //     for (int i = k; i < nums.size(); i++) {
    //         q.pop(nums[i-k]);
    //         q.push(nums[i]);
    //         res.push_back(q.front());
    //     }
    //     return res;
    // }

    // 347. 前 K个高频元素 （优先级队列，一刷有参考）
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++) {
            map[nums[i]]++;
        }
        // 定义一个大小为k的小顶堆
        priority_queue<pair<int, int>, vector<pair<int, int> >, mycomparision > pri_que;
        for (unordered_map<int, int>::iterator it = map.begin(); it != map.end(); it++) {
            pri_que.push(*it);
            if(pri_que.size() > k) {    // 如果小顶堆多于k个元素，就弹出最小的顶
                pri_que.pop();
            }
        }
        vector<int> res(k);
        for (int i = k-1; i >= 0; i--) {
            res[i] = pri_que.top().first;
            pri_que.pop();
        }
        return res;
    }
};

int main() {
    Solution solution;
    // 232. 用栈实现队列
    // int x1 = 1, x2 = 2;
    // MyQueue* obj = new MyQueue();
    // obj->push(x1);
    // obj->push(x2);
    // int param_2 = obj->pop();
    // int param_3 = obj->peek();
    // bool param_4 = obj->empty();
    // cout<<param_2<<" "<<param_3<<" "<<param_4;

    // 225. 用队列实现栈
    // MyStack* obj = new MyStack();
    // int x1 = 1, x2 = 2;
    // obj->push(x1);
    // obj->push(x2);
    // int param_2 = obj->pop();
    // int param_3 = obj->top();
    // bool param_4 = obj->empty();
    // cout<<param_2<<" "<<param_3<<" "<<param_4;

    // 20. 有效的括号
    // bool res = solution.isValid("([{}])))");
    // cout<<res;

    // 1047. 删除字符串中的所有相邻重复项
    // string res = solution.removeDuplicates("abbaca");
    // cout<<res;

    // 150. 逆波兰表达式求值
    // vector<string> tokens = {"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
    // int res = solution.evalRPN(tokens);
    // cout<<res;

    // 239. 滑动窗口最大值
    // vector<int> nums = {1,3,-1,-3,5,3,6,7};
    // vector<int> res = solution.maxSlidingWindow(nums, 3);
    // for (int i = 0; i < res.size(); i++) {
    //     cout<<res[i]<<" ";
    // }

    // 347. 前 K个高频元素
    vector<int> nums = {1,1,1,2,2,3};
    int k = 2;
    vector<int> res = solution.topKFrequent(nums, k);
    for (int i = 0; i < k; i++) {
        cout<<res[i]<<" ";
    }
}