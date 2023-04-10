#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<stack>
#include<regex>
#include<unordered_set>
#include<unordered_map>

using namespace std;

class Solution {
public:
    // 344. 反转字符串
    // void reverseString(vector<char>& s) {
    //     int lth = s.size();
    //     char tmp;
    //     for (int i = 0; i <= (lth-1)/2; i++) {
    //         tmp = s[i];
    //         s[i] = s[lth-1-i];
    //         s[lth-1-i] = tmp;
    //     }
    // }

    // 541. 反转字符串II
    // string reverseStr(string s, int k) {
    //     for (int i = 0; i < s.size(); i += (k*2)) {
    //         if (i + 2*k <= s.size()) {
    //             reverse(s.begin()+i, s.begin()+i+k);
    //         } else {
    //             if (i + k <= s.size()) {
    //                 reverse(s.begin()+i, s.begin()+i+k);
    //             } else {
    //                 reverse(s.begin()+i, s.end());
    //             }
    //         }
    //     }
    //     return s;
    // }

    // 剑指offer 05. 替换空格
    // string replaceSpace(string s) {
    //     int count = 0;
    //     for (int i = 0; i < s.size(); i++) {
    //         if (s[i] == ' ') {
    //             count++;
    //         }
    //     }
    //     s.resize(s.size() + count*2);
    //     int j = s.size() - 1;
    //     int i = j - count*2;
    //     for (; i >= 0; i--) {
    //         if (s[i] != ' ') {
    //             s[j--] = s[i];
    //         } else {
    //             s[j--] = '0';
    //             s[j--] = '2';
    //             s[j--] = '%';
    //         }
    //     }
    //     return s;
    // }

    // 151. 颠倒字符串中的单词
    // string reverseWords(string s) {
    //     int i, j = s.size() - 1;
    //     string res = "";
    //     while (j >= 0) {
    //         while (s[j] == ' ') {
    //             j--;
    //             if (j < 0) {
    //                 break;
    //             }
    //         }
    //         i = j;
    //         if (i < 0) {
    //             break;
    //         }
    //         while (s[i] != ' ') {
    //             i--;
    //             if (i < 0) {
    //                 break;
    //             }
    //         }
    //         if (j >= 0) {
    //             res.append(s.begin()+i+1, s.begin()+j+1);
    //             res.append(" ");
    //             j = i;
    //         }
    //     }
    //     res.erase(res.begin()+res.size()-1);
    //     return res;
    // }

    // 剑指offer 58-II. 左旋转字符串
    // string reverseLeftWords(string s, int n) {
    //     int oldSize = s.size();
    //     s.resize(oldSize + n);
    //     for (int i = 0; i < n; i++) {
    //         s[oldSize+i] = s[i];
    //     }
    //     for (int k = 0; k < oldSize; k++) {
    //         s[k] = s[k + n];
    //     }
    //     s.erase(s.begin()+oldSize-1, s.begin()+oldSize-1+n);
    //     //
    //     return s;
    // }

    // 28. 实现strStr()（一刷有参考） (KMP)
    // // 构造 next 数组
    // void getNext(int* next, string s) {
    //     int j = -1;         // -1的情况
    //     next[0] = j;
    //     for (int i = 1; i < s.size(); i++) {
    //         while (j >= 0 && s[i] != s[j+1]) {
    //             j = next[j];
    //         }
    //         if (s[i] == s[j+1]) {
    //             j++;
    //         }
    //         next[i] = j;
    //     }
    // }
    // int strStr(string haystack, string needle) {
    //     //
    //     if (needle.size() == 0) {
    //         return 0;
    //     }
    //     int next[needle.size()];
    //     getNext(next, needle);
    //     int j = -1;
    //     for (int i = 0; i < haystack.size(); i++) {
    //         while (j >= 0 && haystack[i] != needle[j+1]) {
    //             j = next[j];
    //         }
    //         if (haystack[i] == needle[j+1]) {
    //             j++;
    //         }
    //         if (j == needle.size()-1) {
    //             return (i-needle.size()+1);
    //         }
    //     }
    //     return -1;
    // }
    
    // 459. 重复的子字符串（一刷有参考）
    // void getNext(int *next, string s) {
    //     int j = -1;
    //     next[0] = j;
    //     for (int i = 1; i < s.size(); i++) {
    //         while (j >= 0 && s[i] != s[j+1]) {
    //             j = next[j];
    //         }
    //         if (s[i] == s[j+1]) {
    //             j++;
    //         }
    //         next[i] = j;
    //     }
    // }
    // bool repeatedSubstringPattern(string s) {
    //     // // 法一
    //     // string newS = s + s;
    //     // // 掐头去尾
    //     // newS.erase(newS.begin());
    //     // newS.erase(newS.end()-1);
    //     // if (newS.find(s) != string::npos) {
    //     //     return true;
    //     // }
    //     // return false;
    //
    //     // // 法二：KMP
    //     // // 在由重复子串组成的字符串中，最长相等前后缀不包含的子串就是最小重复子串
    //     // // 构造 next 数组
    //     // int lth = s.size();
    //     // if (lth == 0) {
    //     //     return false;
    //     // }
    //     // int next[lth];
    //     // getNext(next, s);
    //     // if (next[lth-1] != -1 && lth%(lth-(next[lth-1]+1)) == 0) {
    //     //     return true;
    //     // }
    //     // return false;
    // }

    // 925. 长按键入
    // bool isLongPressedName(string name, string typed) {
    //     int i = 0, j = 0;
    //     while (i < name.size()) {
    //         if (name[i] == typed[j]) {
    //             i++;
    //             j++;
    //         } else if (j > 0 && typed[j] == typed[j-1]) {
    //             j++;
    //         } else {
    //             return false;
    //         }
    //     }
    //     if (j == typed.size()) {
    //         return true;
    //     } else {
    //         while (j < typed.size()) {
    //             if (typed[j] == name[i - 1]) {
    //                 j++;
    //             } else {
    //                 return false;
    //             }
    //         }
    //     }
    //     return true;;
    // }

    // 844. 比较含退格的字符串
    // // 法一：栈，写得比较傻
    // bool backspaceCompare(string s, string t) {
    //     stack<char> st_s, st_t;
    //     for (char c_s : s) {
    //         if (c_s != '#') {
    //             st_s.push(c_s);
    //         } else {
    //             if (!st_s.empty()) {
    //                 st_s.pop();
    //             }
    //         }
    //     }
    //     for (char c_t : t) {
    //         if (c_t != '#') {
    //             st_t.push(c_t);
    //         } else {
    //             if (!st_t.empty()) {
    //                 st_t.pop();
    //             }
    //         }
    //     }
    //     int size_s = st_s.size(), size_t = st_t.size();
    //     if (size_s != size_t) {
    //         return false;
    //     }
    //     while (!st_s.empty()) {
    //         char c_s = st_s.top();
    //         char c_t = st_t.top();
    //         if (c_s != c_t) {
    //             return false;
    //         }
    //         st_s.pop();
    //         st_t.pop();
    //     }
    //     return true;
    // }
    // // 
    // // 法二：双指针，不占用额外空间 （一刷有参考）
    // bool backspaceCompare(string S, string T) {
    //     int sSkipNum = 0; // 记录S的#数量
    //     int tSkipNum = 0; // 记录T的#数量
    //     int i = S.size() - 1;
    //     int j = T.size() - 1;
    //     while (1) {
    //         while (i >= 0) { // 从后向前，消除S的#
    //             if (S[i] == '#') sSkipNum++;
    //             else {
    //                 if (sSkipNum > 0) sSkipNum--;
    //                 else break;
    //             }
    //             i--;
    //         }
    //         while (j >= 0) { // 从后向前，消除T的#
    //             if (T[j] == '#') tSkipNum++;
    //             else {
    //                 if (tSkipNum > 0) tSkipNum--;
    //                 else break;
    //             }
    //             j--;
    //         }
    //         // 后半部分#消除完了，接下来比较S[i] != T[j]
    //         if (i < 0 || j < 0) break; // S 或者T 遍历到头了
    //         if (S[i] != T[j]) return false;
    //         i--;j--;
    //     }
    //     // 说明S和T同时遍历完毕
    //     if (i == -1 && j == -1) return true;
    //     return false;
    // }

    // 831. 隐藏个人信息
    // string maskPII(string s) {
    //     string res;
    //     bool isEmail = false, isTel = true;
    //     for (char c : s) {
    //         if (c == '@') {
    //             isEmail = true;
    //             isTel = false;
    //             break;
    //         }
    //     }
    //     // 如果是邮件地址
    //     if (isEmail) {
    //         res = s;
    //         int idx = 0;
    //         for (; idx < s.size(); idx++) {
    //             if (s[idx] == '@') {
    //                 break;
    //             }
    //         }
    //         if (idx == 2) {
    //             res.insert(1, "*****");
    //         } else {
    //             res.replace(1, idx - 2, "*****");
    //         }
    //         for (int i = 0; i < res.size(); i++) {
    //             if ('A' <= res[i] && res[i] <= 'Z') {
    //                 res[i] = res[i] + ('a' - 'A');
    //             }
    //         } 
    //     }
    //     // 如果是电话号码
    //     if (isTel) {
    //         res.insert(0, "***-***-");
    //         string nums = "";
    //         for (char c : s) {
    //             if (c >= '0' && c <= '9') {
    //                 nums.push_back(c);
    //             }
    //         }
    //         res += nums.substr(nums.size() - 4, 4);
    //         if (nums.size() == 10) {
    //             return res;
    //         }
    //         res.insert(0, "-");
    //         int count = nums.size() - 10;
    //         while (count--) {
    //             res.insert(0, "*");
    //         }
    //         res.insert(0, "+");
    //     }
    //     return res;
    // }
    // // 官方解法
    // vector<string> country = {"", "+*-", "+**-", "+***-"};
    // string maskPII(string s) {
    //     string res;
    //     int at = s.find("@");
    //     if (at != string::npos) {
    //         transform(s.begin(), s.end(), s.begin(), ::tolower);
    //         return s.substr(0, 1) + "*****" + s.substr(at - 1);
    //     }
    //     s = regex_replace(s, regex("[^0-9]"), "");
    //     return country[s.size() - 10] + "***-***-" + s.substr(s.size() - 4);
    // }

    // 3. 无重复字符的最长子串
    // int lengthOfLongestSubstring(string s) {
    //     if (s.size() == 0) {
    //         return 0;
    //     }
    //     unordered_set<char> set;
    //     set.clear();
    //     int left = 0, res = 0;
    //     for (int i = 0; i < s.size(); i++) {
    //         while (set.find(s[i]) != set.end()) {
    //             set.erase(s[left++]);
    //         }
    //         set.insert(s[i]);
    //         res = max(res, i - left + 1);
    //     }
    //     return res;
    // }

    // 2399. 检查相同字母间的距离
    // bool checkDistances(string s, vector<int>& distance) {
    //     unordered_map<char, int> map;
    //     for (int i = 0; i < s.size(); i++) {
    //         if (map.find(s[i]) == map.end()) {
    //             map[s[i]] = i;
    //         } else {
    //             int dist = i - map[s[i]] - 1;
    //             if (distance[s[i] - 'a'] != dist) {
    //                 return false;
    //             }
    //         }
    //     }
    //     return true;
    // }
};

int main() {
    Solution solution;

    // 344. 反转字符串
    // vector<char> s = {'h','e','l','l','o'};
    // solution.reverseString(s);
    // for (int i = 0; i < s.size(); i++) {
    //     cout<<s[i]<<" ";
    // }

    // 541. 反转字符串II
    // string s = "";
    // string res = solution.reverseStr(s, 2);
    // cout<<res;

    // 剑指offer 05. 替换空格
    // string s = "We are happy.";
    // string res = solution.replaceSpace(s);
    // cout<<res;

    // 151. 颠倒字符串中的单词
    // string s = "he l";
    // string res = solution.reverseWords(s);
    // cout<<res<<",,,";

    // 剑指offer 58-II. 左旋转字符串
    // string s = "lrloseumgh";
    // string res = solution.reverseLeftWords(s, 6);
    // cout<<res;

    // 28. 实现strStr()
    // string s1 = "mississippi", s2 = "issip";
    // int a = solution.strStr(s1, s2);
    // cout<<a;

    // 459. 重复的子字符串
    // string s = "abab";
    // bool res = solution.repeatedSubstringPattern(s);
    // cout<<res;

    // 925. 长按键入
    // string name = "alex";
    // string typed = "alexxr";
    // cout<<solution.isLongPressedName(name, typed);

    // 844. 比较含退格的字符串
    // string s = "adf##dbd#c", t = "adbc";
    // cout<<solution.backspaceCompare(s, t);

    // 831. 隐藏个人信息
    // string s = "86-(10)12345678";
    // cout<<solution.maskPII(s);

    // 3. 无重复字符的最长子串
    // string s = "bbb";
    // cout<<solution.lengthOfLongestSubstring(s);
}

