#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

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
}

