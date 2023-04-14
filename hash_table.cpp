#include<iostream>
#include<vector>
#include<unordered_set>
#include<unordered_map>
#include<math.h>
#include<algorithm>

using namespace std;

class Solution {
public:
    // 242.有效的字母异位词
    // bool isAnagram(string s, string t) {
    //     int ary[26] = {0};
        // for (int i = 0; i < s.length(); i++) {
        //     ary[s[i]-'a']++;
    //     }
    //     for (int i = 0; i < t.length(); i++) {
    //         ary[t[i]-'a']--;
    //     }
    //     for (int i = 0; i < 26; i++) {
    //         if (ary[i] != 0 ) {
    //             return false;
    //         }
    //     }
    //     return true;
    // }

    // 349.两个数组的交集(一刷有参考)
    // vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    //     unordered_set<int> result_set;
    //     unordered_set<int> nums_set(nums1.begin(), nums1.end());
    //     for (int num : nums2) {
    //         if (nums_set.find(num) != nums_set.end()) {
    //             result_set.insert(num);
    //         }
    //     }
    //     return vector<int>(result_set.begin(), result_set.end());
    // }

    // 202.快乐数
    // bool isHappy(int n) {
    //     int count = 10000;
    //     int num = 0;
    //     while(count--) {
    //         while(n) {
    //             num += pow(n%10, 2);
    //             n /= 10;
    //         }
    //         n = num;
    //         if (num == 1) {
    //             return true;
    //         }
    //         num = 0;
    //     }
    //     return false;
    // }

    // 1.两数之和(哈希表法，一刷有参考)
    // vector<int> twoSum(vector<int>& nums, int target) {
    //     unordered_map<int,int> map;
    //     for (int i = 0; i < nums.size(); i++) {
    //         // 迭代器
    //         unordered_map<int,int>::iterator iter;
    //         iter = map.find(target-nums[i]);
    //         if (iter != map.end()) {
    //             return {iter->second, i};
    //         }
    //         map.insert(pair<int,int>(nums[i], i));
    //     }
    //     return {};
    // }

    // 454.四数相加II
    // int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
    //     unordered_map<int,int> map;
    //     for (int a : nums1) {
    //         for (int b : nums2) {
    //             map[a+b]++;
    //         }
    //     }
    //     int count = 0;
    //     for (int c : nums3) {
    //         for (int d : nums4) {
    //             if (map.find(0-(c+d)) != map.end()) {
    //                 count += map[0-(c+d)];
    //             }
    //         }
    //     }
    //     return count;
    // }

    // 383.赎金信
    // bool canConstruct(string ransomNote, string magazine) {
    //     int ary[26] = {0};
    //     for (int i = 0; i < magazine.size(); i++) {
    //         ary[magazine[i] - 'a']++;
    //     }
    //     for (int i = 0; i < ransomNote.size(); i++) {
    //         ary[ransomNote[i] - 'a']--;
    //     }
    //     for (int i = 0; i < 26; i++) {
    //         if (ary[i] < 0) {
    //             return false;
    //         }
    //     }
    //     return true;
    // }

    // 15.三数之和
    // vector<vector<int>> threeSum(vector<int>& nums) {
    //     vector<vector<int> > res = {};
    //     if (nums.size() < 3) {
    //         return res;
    //     }
    //     // 对数组进行一遍快排
    //     sort(nums.begin(), nums.end());
    //     // a = nums[i], b = nums[left], c = nums[right], left = i+1, right = nums.size()-1
    //     for (int i = 0; i < nums.size(); i++) {
    //         if (nums[i] > 0) {
    //             return res;
    //         }
    //         // 对 a 去重
    //         if (i > 0 && nums[i-1]==nums[i]) {
    //             continue;
    //         }
    //         int left = i+1, right = nums.size()-1;
    //         int sum;
    //         while (left < right) {
    //             sum = nums[i]+nums[left]+nums[right];
    //             if (sum < 0) {
    //                 left++;
    //             } else if (sum > 0) {
    //                 right--;
    //             } else {
    //                 res.push_back(vector<int>{nums[i], nums[left], nums[right]});
    //                 // 对 b, c去重
    //                 while (left<right && nums[left+1]==nums[left]) {
    //                     left++;
    //                 }
    //                 while (left<right && nums[right]==nums[right-1]) {
    //                     right--;
    //                 }
    //                 left++;
    //                 right--;
    //             }
    //         }
    //     }
    //     return res;
    // }

    // 18.四数之和
    // vector<vector<int>> fourSum(vector<int>& nums, int target) {
    //     vector<vector<int> > res = {};
    //     if (nums.size() < 4) {
    //         return res;
    //     }
    //     sort(nums.begin(), nums.end());
    //     for (int i = 0; i < nums.size(); i++) {
    //         if (nums[i] > target && nums[i] >= 0) {
    //             break;
    //         }
    //         if (i > 0 && nums[i] == nums[i-1]) {
    //             continue;
    //         }
    //         for (int j = i+1; j < nums.size(); j++) {
    //             if (nums[i]+nums[j] > target && nums[i]+nums[j] >= 0) {
    //                 break;
    //             }
    //             if (j > i+1 && nums[j] == nums[j-1]) {
    //                 continue;
    //             }
    //             int left = j+1, right = nums.size()-1;
    //             long int sum;
    //             while (left < right) {
    //                 sum = nums[i] + nums[j] + nums[left] + nums[right];
    //                 if (sum > target) {
    //                     right--;
    //                 } else if (sum < target) {
    //                     left++;
    //                 } else {
    //                     res.push_back(vector<int>{nums[i], nums[j], nums[left], nums[right]});
    //                     while (left < right && nums[left] == nums[left+1]) {
    //                         left++;
    //                     }
    //                     while (left < right && nums[right] == nums[right-1]) {
    //                         right--;
    //                     }
    //                     left++;
    //                     right--;
    //                 }
    //             }
    //         }
    //     }
    //     return res;
    // }

    // 205. 同构字符串
    // bool isIsomorphic(string s, string t) {
    //     unordered_map<char, char> map;
    //     unordered_set<char> set;
    //     for (int i = 0; i < s.size(); i++) {
    //         unordered_map<char, char>::iterator it;
    //         it = map.find(s[i]);
    //         if (it != map.end()) {
    //             if (map[s[i]] != t[i]) {
    //                 return false;
    //             }
    //         } else {
    //             if (set.find(t[i]) != set.end()) {
    //                 return false;
    //             }
    //             map.insert(pair<char, char>(s[i], t[i]));
    //             set.insert(t[i]);
    //         }
    //     }
    //     return true;
    // }

    // 1002. 查找共用字符
    // vector<string> commonChars(vector<string>& words) {
    //     vector<int> hash(26, 0);
    //     for (int i = 0; i < words[0].size(); i++) {
    //         hash[words[0][i] - 'a']++;
    //     }
    //     for (int i = 1; i < words.size(); i++) {
    //         vector<int> new_hash(26, 0);
    //         for (int j = 0; j < words[i].size(); j++) {
    //             new_hash[words[i][j] - 'a']++;
    //         }
    //         for (int k = 0; k < 26; k++) {
    //             hash[k] = min(hash[k], new_hash[k]);
    //         }
    //     }
    //     vector<string> res;
    //     for (int i = 0; i < 26; i++) {
    //         while (hash[i]--) {
    //             string tmp;
    //             tmp.push_back(i + 'a');
    //             res.push_back(tmp);
    //         }
    //     }
    //     return res;
    // }

    // 128. 最长连续序列 (一刷参考)
    // int longestConsecutive(vector<int>& nums) {
    //     unordered_set<int> set;
    //     unordered_set<int>::iterator it;
    //     for (int num : nums) {
    //         set.insert(num);
    //     }
    //     int max_len = 0;
    //     for (int num : nums) {
    //         if (set.find(num - 1) == set.end()) {
    //             int tail = num;
    //             while (set.find(tail + 1) != set.end()) {
    //                 tail++;
    //             } 
    //             int len = tail - num + 1;
    //             max_len = max(max_len, len);
    //         }
    //     }
    //     return max_len;
    // }

    // 49. 字母异位词分组
    // vector<vector<string>> groupAnagrams(vector<string>& strs) {
    //     vector<vector<string>> res;
    //     unordered_map<string, vector<string>> map;
    //     for (string s : strs) {
    //         string tmp = s;
    //         sort(tmp.begin(), tmp.end());
    //         map[tmp].push_back(s);
    //     }
    //     unordered_map<string, vector<string>>::iterator it = map.begin();
    //     while (it != map.end()) {
    //         res.push_back(it->second);
    //         it++;
    //     }
    //     return res;
    // }
};

int main() {
    Solution solution;
    
    // 242.有效的字母异位词
    // bool res = solution.isAnagram("rat", "car");
    // cout<<res;

    // 202.快乐数
    // bool res = solution.isHappy(2);
    // cout<<res;

    // 383.赎金信
    // bool res = solution.canConstruct("aa", "aab");
    // cout<<res;

    // 15.三数之和  18. 四数之和
    // vector<int> input = {-3,-2,-1,0,0,1,2,3};
    // vector<vector<int> > res = solution.fourSum(input, 0);
    // for (int i = 0; i < res.size(); i++) {
    //     for (int j = 0; j < 4; j++) {
    //         cout<<res[i][j]<<", ";
    //     }
    //     cout<<endl;
    // }

    // 205. 同构字符串
    // string s = "badc", t = "baba";
    // cout<<solution.isIsomorphic(s, t);

    // 128. 最长连续序列
    // vector<int> nums = {100,4,200,1,3,2};
    // cout<<solution.longestConsecutive(nums);
}