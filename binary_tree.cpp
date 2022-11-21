#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
#include<queue>
#include<unordered_map>

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

    // 257. 二叉树的所有路径 （一刷有参考）
    // // 法一：递归回溯法
    // vector<string> binaryTreePaths(TreeNode* root) {
    //     vector<string> res = {};
    //     binaryTreePaths(root, res, "");
    //     return res;
    // }
    // void binaryTreePaths(TreeNode* node, vector<string>& res, string path) {
    //     if (node == nullptr) {
    //         return;
    //     }
    //     path += to_string(node->val);
    //     if(node->left == nullptr && node->right == nullptr) {
    //         res.push_back(path);
    //         return;
    //     }
    //     if (node->left) {
    //         binaryTreePaths(node->left, res, path + "->");
    //     }
    //     if (node->right) {
    //         binaryTreePaths(node->right, res, path + "->");
    //     }
    // }
    //
    // // 法二：迭代（前序遍历迭代法，加一个存路径的stack，与结点stack同步）
    // vector<string> binaryTreePaths(TreeNode* root) {
    //     stack<string> paths;
    //     stack<TreeNode*> nodes;
    //     vector<string> res = {};
    //     string path;
    //     TreeNode* node;
    //     if (root == nullptr) {
    //         return res;
    //     }
    //     nodes.push(root);
    //     paths.push(to_string(root->val));
    //     while (!nodes.empty()) {
    //         node = nodes.top();
    //         nodes.pop();
    //         path = paths.top();
    //         paths.pop();
    //         if (node->right) {
    //             nodes.push(node->right);
    //             paths.push(path + "->" + to_string(node->right->val));
    //         }
    //         if (node->left) {
    //             nodes.push(node->left);
    //             paths.push(path + "->" + to_string(node->left->val));
    //         }
    //         if (node->left == nullptr && node->right == nullptr) {
    //             res.push_back(path);
    //         }
    //     }
    //     return res;
    // }

    // 404. 左叶子之和
    // int sumOfLeftLeaves(TreeNode* root) {
    //     queue<TreeNode*> q;
    //     int sum = 0;
    //     if (root == nullptr) {
    //         return 0;
    //     }
    //     q.push(root);
    //     while (!q.empty()) {
    //         int size = q.size();
    //         for (int i = 0; i < size; i++) {
    //             TreeNode* cur = q.front();
    //             q.pop();
    //             if (cur->left) {
    //                 if (cur->left->left == nullptr && cur->left->right == nullptr) {
    //                     sum += cur->left->val;
    //                 } else {
    //                     q.push(cur->left);
    //                 }
    //             }
    //             if (cur->right) {
    //                 q.push(cur->right);
    //             }
    //         }
    //     }
    //     return sum;
    // }

    // 513. 找树左下角的值
    // int findBottomLeftValue(TreeNode* root) {
    //     queue<TreeNode*> q;
    //     q.push(root);
    //     int res = root->val;
    //     while (!q.empty()) {
    //         int size = q.size();
    //         for (int i = 0; i < size; i++) {
    //             TreeNode* cur = q.front();
    //             q.pop();
    //             if (cur->left) {
    //                 q.push(cur->left);
    //             }
    //             if (cur->right) {
    //                 q.push(cur->right);
    //             }
    //         }
    //         if (!q.empty()) {
    //             res = q.front()->val;
    //         }
    //     }
    //     return res;
    // }

    // 112. 路径总和
    // bool hasPathSum(TreeNode* root, int targetSum) {
    //     vector<int> res = {};
    //     pathSum(root, res, 0);
    //     for (int i = 0; i < res.size(); i++) {
    //         if (res[i] == targetSum) {
    //             return true;
    //         }
    //     }
    //     return false;
    // }
    // void pathSum(TreeNode* node, vector<int>& res, int sum) {
    //     if (node == nullptr) {
    //         return;
    //     }
    //     sum += node->val;
    //     if (node->left == nullptr && node->right == nullptr) {
    //         res.push_back(sum);
    //     }
    //     if (node->left) {
    //         pathSum(node->left, res, sum);
    //     }
    //     if (node->right) {
    //         pathSum(node->right, res, sum);
    //     }
    // }

    // 113. 路径总和 II
    // vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
    //     vector<vector<int> > res;
    //     vector<int> path;
    //     pathSum(root, res, path, targetSum);
    //     return res;
    // }
    // void pathSum(TreeNode* node, vector<vector<int> >& res, vector<int> path, int count) {
    //     if (node == nullptr) {
    //         return;
    //     }
    //     count -= node->val;
    //     path.push_back(node->val);
    //     if (node->left == nullptr && node->right == nullptr && count == 0) {
    //         res.push_back(path);
    //         return;
    //     }
    //     if (node->left) {
    //         pathSum(node->left, res, path, count);
    //     }
    //     if (node->right) {
    //         pathSum(node->right, res, path, count);
    //     }
    // }

    // 106. 从中序与后序遍历序列构造二叉树
    // TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    //     if (inorder.size() == 0) {
    //         return nullptr;
    //     }
    //     return build(inorder, postorder);
    // }
    // TreeNode* build(vector<int>& inorder, vector<int>& postorder) {
    //     if (inorder.size() == 0) {
    //         return nullptr;
    //     }
    //     int v = postorder[postorder.size()-1];
    //     TreeNode* root = new TreeNode(v);       // 根节点
    //     // 可能只有一个节点：
    //     if (postorder.size() == 1) {
    //         return root;
    //     }
    //     vector<int> left_in, right_in, left_post, right_post;
    //     // left_in
    //     int idx;
    //     for (idx = 0; idx < inorder.size(); idx++) {
    //         if (inorder[idx] != v) {
    //             left_in.push_back(inorder[idx]);
    //         }
    //         else {
    //             break;
    //         }
    //     }
    //     //right_in
    //     for (int i = idx+1; i < inorder.size(); i++) {
    //         right_in.push_back(inorder[i]);
    //     }
    //     //left_post
    //     int idx2;
    //     for (idx2 = 0; idx2 < left_in.size(); idx2++) {
    //         left_post.push_back(postorder[idx2]);
    //     }
    //     // right_post
    //     for (int i = idx2; i < postorder.size()-1; i++) {
    //         right_post.push_back(postorder[i]);
    //     }
    //     root->left = build(left_in, left_post);
    //     root->right = build(right_in, right_post);
    //     return root;
    // }

    // 105. 从前序与中序遍历序列构造二叉树
    // unordered_map<int, int> map;
    // TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    //     if (preorder.size() == 0) {
    //         return nullptr;
    //     }
    //     for (int i = 0; i < preorder.size(); i++) {
    //         map[inorder[i]] = i;     // 减少查找下标时间
    //     }
    //     return build(preorder, inorder, 0, preorder.size()-1, 0, inorder.size()-1);
    // }
    // TreeNode* build(vector<int>& preorder, vector<int>& inorder, int pre_begin, int pre_end, int in_begin, int in_end) {
    //     if (in_begin > in_end) {
    //         return nullptr;
    //     }
    //     int rootV = preorder[pre_begin];
    //     TreeNode* root = new TreeNode(rootV);
    //     if (in_begin == in_end) {
    //         return root;
    //     }
    //     int idx = map[rootV];
    //     // 左
    //     int left_in_begin = in_begin;
    //     int left_in_end = idx-1;
    //     int left_pre_begin = pre_begin+1;
    //     int left_pre_end = left_pre_begin+left_in_end-left_in_begin;
    //     root->left = build(preorder, inorder, left_pre_begin, left_pre_end, left_in_begin, left_in_end);
    //     // 右
    //     int right_in_begin = idx+1;
    //     int right_in_end = in_end;
    //     int right_pre_begin = left_pre_end+1;
    //     int right_pre_end = pre_end;
    //     root->right = build(preorder, inorder, right_pre_begin, right_pre_end, right_in_begin, right_in_end);
    //
    //     return root;
    // }

    // 654. 最大二叉树
    // unordered_map<int, int> map;
    // TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
    //     if (nums.size() == 0) {
    //         return nullptr;
    //     }
    //     for (int i = 0; i < nums.size(); i++) {
    //         map[nums[i]] = i;
    //     }
    //     return buildMax(nums, 0, nums.size());
    // }
    // TreeNode* buildMax(vector<int>& nums, int begin, int end) {
    //     if (begin >= end) {
    //         return nullptr;
    //     }
    //     int rootV = *max_element(nums.begin() + begin, nums.begin() + end);
    //     TreeNode* root = new TreeNode(rootV);
    //     if (end - begin == 1) {
    //         return root;
    //     }
    //     int idx = map[rootV];
    //     int left_begin = begin;
    //     int left_end = idx;
    //     int right_begin = idx + 1;
    //     int right_end = end;
    //     root->left = buildMax(nums, left_begin, left_end);
    //     root->right = buildMax(nums, right_begin, right_end);
    //
    //     return root;
    // }

    // 617. 合并二叉树
    // TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
    //     if (root1 == nullptr) {
    //         return root2;
    //     }
    //     if (root2 == nullptr) {
    //         return root1;
    //     }
    //     root1->val += root2->val;
    //     root1->left = mergeTrees(root1->left, root2->left);
    //     root1->right = mergeTrees(root1->right, root2->right);
    //     return root1;
    // }

    // 700. 二叉搜索树中的搜索
    // TreeNode* searchBST(TreeNode* root, int val) {
    //     if (root == nullptr) {
    //         return nullptr;
    //     }
    //     int rootV = root->val;
    //     if (val == rootV) {
    //         return root;
    //     } else if (val > rootV) {
    //         return searchBST(root->right, val);
    //     } else {
    //         return searchBST(root->left, val);
    //     }
    // }
    // // 普通二叉树适用：
    // // TreeNode* searchBST(TreeNode* root, int val) {
    // //     if(root == NULL)
    // //         return NULL;
    // //     if(root->val == val)
    // //         return root;
    // //     TreeNode *node_left=searchBST(root->left,val);
    // //     TreeNode *node_right=searchBST(root->right,val);
    // //     if(node_left!=NULL)
    // //         return node_left;
    // //     if(node_right!=NULL)
    // //         return node_right;
    // //     return NULL;
    // // }

    // 98. 验证二叉搜索树
    // // 中序遍历是有序的就是有效的二叉搜索树
    // bool isValidBST(TreeNode* root) {
    //     vector<int> vec = {};
    //     traversal(root, vec);
    //     for (int i = 0; i < vec.size()-1; i++) {
    //         if (vec[i] > vec[i+1]) {
    //             return false;
    //         }
    //     }
    //     return true;
    // }
    // // 得到中序遍历结果
    // void traversal(TreeNode* node, vector<int>& vec) {
    //     if (node == nullptr) {
    //         return;
    //     }
    //     traversal(node->left, vec);
    //     vec.push_back(node->val);
    //     traversal(node->right, vec);
    //     return;
    // }
    //
    // // 参考别人的：
    // long int last = LONG_MIN;
    // bool isValidBST(TreeNode* root) {
    //     if (root == nullptr) {
    //         return true;
    //     }
    //     if (isValidBST(root->left)) {
    //         if (last < root->val) {
    //             last = root->val;
    //             return isValidBST(root->right);
    //         }
    //     }
    //     return false;
    // }

    // 530. 二叉搜索树的最小绝对差(一刷有参考)
    // int res = INT_MAX;
    // TreeNode* pre;
    // int getMinimumDifference(TreeNode* root) {
    //     traversal(root);
    //     return res;
    // }
    // void traversal(TreeNode* node) {
    //     if (node == nullptr) {
    //         return;
    //     }
    //     traversal(node->left);
    //     if (pre != nullptr) {
    //         res = min(res, abs(pre->val - node->val));
    //     }
    //     pre = node;
    //     traversal(node->right);
    // }

    // 501. 二叉搜索树中的众数
    // // 这是普遍适用代码
    // unordered_map<int, int> map;
    // vector<int> findMode(TreeNode* root) {
    //     vector<int> res = {};
    //     traversal(root);
    //     int count = 0;
    //     unordered_map<int,int>::iterator iter;
    //     vector<pair<int, int>> vec(map.begin(), map.end());
    //     sort(vec.begin(), vec.end(), cmp); // 给频率排个序
    //     res.push_back(vec[0].first);
    //     for (int i = 1; i < vec.size(); i++) {
    //         // 取最高的放到result数组中
    //         if (vec[i].second == vec[0].second) {
    //             res.push_back(vec[i].first);
    //         }
    //         else break;
    //     }
    //     return res;
    // }
    // bool static cmp (const pair<int, int>& a, const pair<int, int>& b) {
    //     return a.second > b.second;
    // }
    // void traversal(TreeNode* node) {
    //     if (node == nullptr) {
    //         return;
    //     }
    //     map[node->val]++;
    //     traversal(node->left);
    //     traversal(node->right);
    // }

    // 236. 二叉树的最近公共祖先（一刷有参考）
    // 需要自底向上地查找，即回溯，后序遍历即为回溯
    // TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    //     if (root == p || root == q || root == nullptr) {
    //         return root;
    //     }
    //     TreeNode* left = lowestCommonAncestor(root->left, p, q);
    //     TreeNode* right = lowestCommonAncestor(root->right, p, q);
    //     if (left != nullptr && right != nullptr) {
    //         return root;
    //     }
    //     if (left == nullptr) {
    //         return right;
    //     }
    //     return left;
    // }

    // 235. 二叉搜索树的最近公共祖先 (重写)
    // TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    //     if (root == NULL) return root;
    //                                                     // 中
    //     if (root->val > p->val && root->val > q->val) {   // 左
    //         TreeNode* left = lowestCommonAncestor(root->left, p, q);
    //         if (left != NULL) {
    //             return left;
    //         }
    //     }
    // 
    //     if (root->val < p->val && root->val < q->val) {   // 右
    //         TreeNode* right = lowestCommonAncestor(root->right, p, q);
    //         if (right != NULL) {
    //             return right;
    //         }
    //     }
    //     return root;
    // }

    // 701. 二叉搜索树中的插入操作
    // TreeNode* insertIntoBST(TreeNode* root, int val) {
    //     if (root == nullptr) {
    //         TreeNode* node = new TreeNode(val);
    //         return node;
    //     }
    //     insert_val(root, val);
    //     return root;
    // }
    //
    // void insert_val(TreeNode* root, int val) {
    //     if (root->val < val) {
    //         if (root->right == nullptr) {
    //             TreeNode* node = new TreeNode(val);
    //             root->right = node;
    //         } else {
    //             insert_val(root->right, val);
    //         }
    //     }
    //     if (root->val > val) {
    //         if (root->left == nullptr) {
    //             TreeNode* node = new TreeNode(val);
    //             root->left = node;
    //         } else {
    //             insert_val(root->left, val);
    //         }
    //     }
    // }

    // 450. 删除二叉搜索树中的节点
    // // 注意释放内存
    // TreeNode* deleteNode(TreeNode* root, int key) {
    //     if (root == nullptr) {
    //         return root;
    //     }
    //     if (root->val == key) {
    //         if (root->left == nullptr && root->right == nullptr) {
    //             delete root;
    //             return nullptr;
    //         } else if (root->left == nullptr) {
    //             TreeNode* node = root->right;
    //             delete root;
    //             return node;
    //         } else if (root->right == nullptr) {
    //             TreeNode* node = root->left;
    //             delete root;
    //             return node;
    //         } else {
    //             TreeNode* cur = root->right;
    //             while (cur->left) {
    //                 cur = cur->left;
    //             }
    //             cur->left = root->left;
    //             TreeNode* tmp = root;
    //             root = root->right;
    //             delete tmp;
    //             return root;
    //         }
    //     }
    //     if (root->val > key) {
    //         root->left = deleteNode(root->left, key);
    //     }
    //     if (root->val < key) {
    //         root->right = deleteNode(root->right, key);
    //     }
    //     return root;
    // }

    // 669. 修剪二叉搜索树
    // TreeNode* trimBST(TreeNode* root, int low, int high) {
    //     if (root == nullptr) {
    //         return root;
    //     }
    //     if (root->val < low) {  // 小于左极限，只需要关注它右子树的节点
    //         return trimBST(root->right, low, high);
    //     }
    //     if (root->val > high) {  // 大于右极限，只需要关注它左子树的节点
    //         return trimBST(root->left, low, high);
    //     }
    //     root->left = trimBST(root->left, low, high);
    //     root->right = trimBST(root->right, low, high);
    //     return root;
    // }

    // 108. 将有序数组转换为二叉搜索树
    // // 递归版
    // TreeNode* sortedArrayToBST(vector<int>& nums) {
    //     return traversal(nums, 0, nums.size()-1);
    // }
    // TreeNode* traversal(vector<int>& nums, int low, int high) {
    //     // 这段可以优化一下
    //     // if (low == high) {
    //     //     TreeNode* root = new TreeNode(nums[low]);
    //     //     return root;
    //     // }
    //     // if (high - low == 1) {
    //     //     TreeNode* root = new TreeNode(nums[low]);
    //     //     root->right = new TreeNode(nums[high]);
    //     //     return root;
    //     // }
    //     if (low > high) {
    //         return nullptr;
    //     }
    //     int mid = low + (high-low)/2;
    //     TreeNode* root = new TreeNode(nums[mid]);
    //     root->left = traversal(nums, low, mid-1);
    //     root->right = traversal(nums, mid+1, high);
    //     return root;
    // }
    //
    // // 迭代版（需要理解）
    // TreeNode* sortedArrayToBST(vector<int>& nums) {
    //     if (nums.size() == 0) return nullptr;

    //     TreeNode* root = new TreeNode(0);   // 初始根节点
    //     queue<TreeNode*> nodeQue;           // 放遍历的节点
    //     queue<int> leftQue;                 // 保存左区间下标
    //     queue<int> rightQue;                // 保存右区间下标
    //     nodeQue.push(root);                 // 根节点入队列
    //     leftQue.push(0);                    // 0为左区间下标初始位置
    //     rightQue.push(nums.size() - 1);     // nums.size() - 1为右区间下标初始位置

    //     while (!nodeQue.empty()) {
    //         TreeNode* curNode = nodeQue.front();
    //         nodeQue.pop();
    //         int left = leftQue.front(); leftQue.pop();
    //         int right = rightQue.front(); rightQue.pop();
    //         int mid = left + ((right - left) / 2);

    //         curNode->val = nums[mid];       // 将mid对应的元素给中间节点

    //         if (left <= mid - 1) {          // 处理左区间
    //             curNode->left = new TreeNode(0);
    //             nodeQue.push(curNode->left);
    //             leftQue.push(left);
    //             rightQue.push(mid - 1);
    //         }

    //         if (right >= mid + 1) {         // 处理右区间
    //             curNode->right = new TreeNode(0);
    //             nodeQue.push(curNode->right);
    //             leftQue.push(mid + 1);
    //             rightQue.push(right);
    //         }
    //     }
    //     return root;
    // }
};

int main() {
    Solution solution;
}