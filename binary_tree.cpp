#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
#include<queue>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// N叉树定义
// class Node {
// public:
//     int val;
//     vector<Node*> children;
//     Node() {}
//     Node(int _val) {
//         val = _val;
//     }
//     Node(int _val, vector<Node*> _children) {
//         val = _val;
//         children = _children;
//     }
// };

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};


class Solution {
public:
    // 前中后序遍历：递归法
    // void traversal(TreeNode *cur, vector<int>& vec) {
    //     if (cur == NULL) {
    //         return;
    //     }
    //     vec.push_back(cur->val);
    //     traversal(cur->left, vec);
    //     traversal(cur->right, vec);
    // }
    // vector<int> preorderTraversal(TreeNode* root) {
    //     vector<int> res = {};
    //     traversal(root, res);
    //     return res;
    // }

    // 前序遍历：迭代法
    // vector<int> preorderTraversal(TreeNode* root) {
    //     stack<TreeNode*> st;
    //     vector<int> res = {};
    //     if (root == nullptr) {
    //         return res;
    //     }
    //     st.push(root);
    //     TreeNode* temp;
    //     while (!st.empty()) {
    //         temp = st.top();
    //         res.push_back(temp->val);
    //         st.pop();
    //         // 注意：空结点不入栈，所以需要有if判定
    //         if (temp->right) {
    //             st.push(temp->right);
    //         }
    //         if (temp->left) {
    //             st.push(temp->left);
    //         } 
    //     }
    //     return res;
    // }

    // 后序遍历：迭代法。与前序遍历对应。
    // vector<int> postorderTraversal(TreeNode* root) {
    //     stack<TreeNode*> st;
    //     vector<int> res = {};
    //     if (root == nullptr) {
    //         return res;
    //     }
    //     st.push(root);
    //     TreeNode* temp;
    //     while (!st.empty()) {
    //         temp = st.top();
    //         res.push_back(temp->val);
    //         st.pop();
    //         // 注意：空结点不入栈，所以需要有if判定.
    //         // 左先压入栈，出栈变成右→左
    //         if (temp->left) {
    //             st.push(temp->left);
    //         }
    //         if (temp->right) {
    //             st.push(temp->right);
    //         } 
    //     }
    //     // 现在是中→右→左，反转一下就变为左→右→中，后序遍历
    //     reverse(res.begin(), res.end());
    //     return res;
    // }

    // 中序遍历：迭代法 （理解）
    // vector<int> inorderTraversal(TreeNode* root) {
    //     vector<int> res = {};
    //     if (root == nullptr) {
    //         return res;
    //     }
    //     stack<TreeNode*> st;
    //     TreeNode* cur = root;
    //     while (cur != nullptr || !st.empty()) {
    //         if (cur != nullptr) {    // 说明上一个访问的结点有左or右孩子，先将自己压栈，继续查看是否自己也有左孩子
    //             st.push(cur);
    //             cur = cur->left;
    //         } else {                // 说明上一个访问的结点一定没有左孩子了（这次深搜到头），那么先栈顶弹出，再查看栈顶结点有没有右孩子
    //             cur = st.top();
    //             res.push_back(cur->val);
    //             st.pop();
    //             cur = cur->right;
    //         }
    //     }
    //     return res;
    // }

    // 前中后序遍历：标记迭代法
    // vector<int> inorderTraversal(TreeNode* root) {
    //     vector<int> res = {};
    //     stack<TreeNode*> st;
    //     TreeNode* node;
    //     if (root == nullptr) {
    //         return res;
    //     }
    //     st.push(root);
    //     while (!st.empty()) {
    //         node = st.top();
    //         if (node != nullptr) {
    //             st.pop();
    //             // 右（因为是入栈）
    //             if (node->right) {
    //                 st.push(node->right);
    //             }
    //             // 中，并标记
    //             st.push(node);
    //             st.push(nullptr);
    //             // 左
    //             if (node->left) {
    //                 st.push(node->left);
    //             }
    //         } else {
    //             st.pop();
    //             node = st.top();
    //             res.push_back(node->val);
    //             st.pop();
    //         }
    //     }
    //     return res;
    // }

    // 102. 二叉树的层序遍历  ||  107. 二叉树的层序遍历 II（大数组翻转一下就行了）
    // vector<vector<int>> levelOrder(TreeNode* root) {
    //     queue<TreeNode*> q;
    //     vector<vector<int> > res = {};
    //     vector<int> vec = {};
    //     TreeNode* cur;
    //     if (root == nullptr) {
    //         return res;
    //     }
    //     q.push(root);
    //     q.push(nullptr);
    //     while (!q.empty()) {
    //         cur = q.front();
    //         if (cur == nullptr) {
    //             q.pop();
    //             vec = {};
    //         } else {
    //             q.pop();
    //             vec.push_back(cur->val);
    //             if (cur->left) {
    //                 q.push(cur->left);
    //             }
    //             if (cur->right) {
    //                 q.push(cur->right);
    //             }
    //             if (q.front() == nullptr) {
    //                 q.push(nullptr);
    //                 res.push_back(vec);
    //             }
    //         }
    //     }
    //     return res;
    // }

    // 199. 二叉树的右视图
    // vector<int> rightSideView(TreeNode* root) {
    //     queue<TreeNode*> q;
    //     vector<int> res = {};
    //     TreeNode* cur;
    //     if (root == nullptr) {
    //         return res;
    //     }
    //     q.push(root);
    //     q.push(nullptr);
    //     while (!q.empty()) {
    //         cur = q.front();
    //         q.pop();
    //         if (cur != nullptr) {
    //             if (cur->left) {
    //                 q.push(cur->left);
    //             }
    //             if (cur->right) {
    //                 q.push(cur->right);
    //             }
    //             if (q.front() == nullptr) {
    //                 q.push(nullptr);
    //                 res.push_back(cur->val);
    //             }
    //         }
    //     }
    //     return res;
    // }

    // 637. 二叉树的层平均值
    // vector<double> averageOfLevels(TreeNode* root) {
    //     queue<TreeNode*> q;
    //     vector<double> res = {};
    //     double sum = 0;
    //     int count = 0;
    //     TreeNode* cur;
    //     if (root == nullptr) {
    //         return res;
    //     }
    //     q.push(root);
    //     q.push(nullptr);
    //     sum += root->val;
    //     count = 1;
    //     while (!q.empty()) {
    //         cur = q.front();
    //         q.pop();
    //         if (cur != nullptr) {
    //             sum += cur->val;
    //             count++;
    //             if (cur->left) {
    //                 q.push(cur->left);
    //             }
    //             if (cur->right) {
    //                 q.push(cur->right);
    //             }
    //             if (q.front() == nullptr) {
    //                 q.push(nullptr);
    //                 res.push_back(sum/(double)count);
    //                 count = 0;
    //                 sum = 0;
    //             }
    //         }
    //     }
    //     return res;
    // }

    // 429. N叉树的层序遍历
    // vector<vector<int>> levelOrder(Node* root) {
    //     queue<Node*> q;
    //     vector<vector<int> > res = {};
    //     vector<int> vec = {};
    //     if (root == nullptr) {
    //         return res;
    //     }
    //     q.push(root);
    //     q.push(nullptr);
    //     Node* cur;
    //     while (!q.empty()) {
    //         cur = q.front();
    //         q.pop();
    //         if (cur == nullptr) {
    //             vec = {};
    //         } else {
    //             vec.push_back(cur->val);
    //             if (cur->children.size()) {    // 如果有孩子的话
    //                 for (Node* tmp : cur->children) {
    //                     q.push(tmp);
    //                 }
    //             }
    //             if (q.front() == nullptr) {
    //                 q.push(nullptr);
    //                 res.push_back(vec);
    //             }
    //         }
    //     }
    //     return res;
    // }

    // 515. 在每个树行中找最大值
    // vector<int> largestValues(TreeNode* root) {
    //     queue<TreeNode*> q;
    //     vector<int> res = {};
    //     int max;
    //     TreeNode* cur;
    //     if (root == nullptr) {
    //         return res;
    //     }
    //     q.push(root);
    //     q.push(nullptr);
    //     max = root->val;
    //     while (!q.empty()) {
    //         cur = q.front();
    //         q.pop();
    //         if (cur == nullptr) {
    //             if (!q.empty() && q.front() != nullptr) {
    //                 max = q.front()->val;
    //             }
    //         } else {
    //             if (cur->val > max) {
    //                 max = cur->val;
    //             }
    //             if (cur->left) {
    //                 q.push(cur->left);
    //             }
    //             if (cur->right) {
    //                 q.push(cur->right);
    //             }
    //             if (q.front() == nullptr) {
    //                 q.push(nullptr);
    //                 res.push_back(max);
    //             }
    //         }
    //     }
    //     return res;
    // }

    // 116. 填充每个节点的下一个右侧节点指针  || 117. 填充每个节点的下一个右侧节点指针 II
    // Node* connect(Node* root) {
    //     queue<Node*> q;
    //     Node* cur;
    //     if (root != nullptr) {
    //         q.push(root);
    //         q.push(nullptr);
    //         while (!q.empty()) {
    //             cur = q.front();
    //             q.pop();
    //             if (cur != nullptr) {
    //                 if (cur->left) {
    //                     q.push(cur->left);
    //                 }
    //                 if (cur->right) {
    //                     q.push(cur->right);
    //                 }
    //                 if (q.front() == nullptr) {
    //                     q.push(nullptr);
    //                     cur->next = nullptr;
    //                 } else {
    //                     cur->next = q.front();
    //                 }
    //             }
    //         }
    //     }
    //     return root;
    // }

    // 104. 二叉树的最大深度
    // // 法一：层序遍历（迭代）法
    // int maxDepth(TreeNode* root) {
    //     queue<TreeNode*> q;
    //     int depth = 0;
    //     TreeNode* cur;
    //     if (root == nullptr) {
    //         return depth;
    //     }
    //     q.push(root);
    //     q.push(nullptr);
    //     while (!q.empty()) {
    //         cur = q.front();
    //         q.pop();
    //         if (cur != nullptr) {
    //             if (cur->left) {
    //                 q.push(cur->left);
    //             }
    //             if (cur->right) {
    //                 q.push(cur->right);
    //             }
    //             if (q.front() == nullptr) {
    //                 q.push(nullptr);
    //                 depth++;
    //             }
    //         }
    //     }
    //     return depth;
    // }
    //
    // // 法二：后序遍历（递归）法
    // int maxDepth(TreeNode* root) {
    //     if (root == nullptr) {
    //         return 0;
    //     }
    //     int dp1 = maxDepth(root->left);
    //     int dp2 = maxDepth(root->right);
    //     return (1 + max(dp1, dp2));
    // }

    // 111. 二叉树的最小深度
    // int minDepth(TreeNode* root) {
    //     queue<TreeNode*> q;
    //     int depth = 0;
    //     TreeNode* cur;
    //     if (root == nullptr) {
    //         return depth;
    //     }
    //     q.push(root);
    //     q.push(nullptr);
    //     depth = 1;
    //     while (!q.empty()) {
    //         cur = q.front();
    //         q.pop();
    //         if (cur != nullptr) {
    //             if (cur->left) {
    //                 q.push(cur->left);
    //             }
    //             if (cur->right) {
    //                 q.push(cur->right);
    //             } 
    //             if (!cur->left && !cur->right) {
    //                 return depth;
    //             }
    //             if (q.front() == nullptr) {
    //                 q.push(nullptr);
    //                 depth++;
    //             }
    //         }
    //     }
    //     return depth;
    // }
    // 
    // // 法二
    // int minDepth(TreeNode* root) {
    //     if (root == nullptr) {
    //         return 0;
    //     }
    //     int dp1 = minDepth(root->left);
    //     int dp2 = minDepth(root->right);
    //     if (dp1 == 0 && dp2 != 0) {
    //         return (1 + dp2);
    //     }
    //     if (dp1 != 0 && dp2 == 0) {
    //         return (1 + dp1);
    //     }
    //     return (1 + min(dp1, dp2));
    // }

    // 226. 翻转二叉树
    // TreeNode* invertTree(TreeNode* root) {
    //     if (root == nullptr) {
    //         return root;
    //     }
    //     TreeNode* tmp;
    //     if (!root->left) {
    //         root->left = nullptr;
    //     }
    //     if (!root->right) {
    //         root->right = nullptr;
    //     }
    //     tmp = root->left;
    //     root->left = root->right;
    //     root->right = tmp;
    //     if (root->left != nullptr) {
    //         invertTree(root->left);
    //     }
    //     if (root->right != nullptr) {
    //         invertTree(root->right);
    //     }
    //     return root;
    // }

    // 101. 对称二叉树
    // // 法一：迭代
    // bool isSymmetric(TreeNode* root) {
    //     queue<TreeNode*> q;
    //     vector<int> vec1, vec2;
    //     TreeNode* cur;
    //     if (root == nullptr) {
    //         return true;
    //     }
    //     q.push(root);
    //     q.push(nullptr);
    //     while (!q.empty()) {
    //         cur = q.front();
    //         q.pop();
    //         if (cur != nullptr) {
    //             if (cur->left) {
    //                 q.push(cur->left);
    //                 vec1.push_back(cur->left->val);
    //             } else {
    //                 vec1.push_back(999);
    //             }
    //             if (cur->right) {
    //                 q.push(cur->right);
    //                 vec1.push_back(cur->right->val);
    //             } else {
    //                 vec1.push_back(999);
    //             }
    //             if (q.front() == nullptr) {
    //                 q.push(nullptr);
    //                 vec2 = vec1;
    //                 reverse(vec1.begin(), vec1.end());
    //                 if (vec2 != vec1) {
    //                     return false; 
    //                 }
    //                 vec1 = {};
    //             }
    //         }
    //     }
    //     return true;
    // }
    //
    // // 法二：递归
    // bool isSymmetric(TreeNode* root) {
    //     return isSym(root->left, root->right);
    // }
    //
    // bool isSym(TreeNode* left, TreeNode* right) {
    //     if (left == nullptr && right == nullptr) {
    //         return true;
    //     }
    //     if (left == nullptr || right == nullptr || left->val != right->val) {
    //         return false;
    //     }
    //     return (isSym(left->right, right->left) && isSym(left->left, right->right));
    // }

    // 222. 完全二叉树的节点个数
    // //  法一：递归
    // int countNodes(TreeNode* root) {
    //     if (root == nullptr) {
    //         return 0;
    //     }
    //     return (1 + countNodes(root->left) + countNodes(root->right));
    // }
    //
    // // 法二：遍历
    // int countNodes(TreeNode* root) {
    //     queue<TreeNode*> q;
    //     TreeNode* cur;
    //     int count = 0;
    //     if (root == nullptr) {
    //         return 0;
    //     }
    //     q.push(root);
    //     while(!q.empty()) {
    //         int size = q.size();
    //         for (int i = 0; i < size; i++) {
    //             cur = q.front();
    //             q.pop();
    //             count++;
    //             if (cur->left) {
    //                 q.push(cur->left);
    //             }
    //             if (cur->right) {
    //                 q.push(cur->right);
    //             }
    //         }
    //     }
    //     return count;
    // }

    // 110. 平衡二叉树
    // bool isBalanced(TreeNode* root) {
    //     if (height(root) >= 0) {
    //         return true;
    //     } else {
    //         return false;
    //     }
    // }
    //
    // int height(TreeNode* root) {
    //     if (root == nullptr) {
    //         return 0;
    //     }
    //     int lh = height(root->left);
    //     int rh = height(root->right);
    //     if (lh >= 0 && rh >= 0 && abs(lh-rh)<=1) {
    //         return (1 + max(lh, rh));
    //     } else {
    //         return -1;
    //     }
    // }
};

int main() {
    Solution solution;
}