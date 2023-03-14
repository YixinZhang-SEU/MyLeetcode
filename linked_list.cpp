#include<iostream>
#include<vector>

using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    // 203.移除链表元素
    // ListNode* removeElements(ListNode* head, int val) {
    //     // 设置一个虚拟头结点
    //     ListNode* dummyhead = new ListNode(0);
    //     dummyhead->next = head;
    //     ListNode* cur = dummyhead;
    //     while (cur->next != NULL) {
    //         if (cur->next->val == val) {
    //             ListNode* tmp = cur->next;
    //             cur->next = cur->next->next;
    //             delete tmp;
    //         } else {
    //             cur = cur->next;
    //         }
    //     }
    //     head = dummyhead->next;
    //     delete dummyhead;
    //     return head;
    // }

    // 206.反转链表
    // ListNode* reverseList(ListNode* head) {
    //     ListNode *tmp, *cur = head, *pre = NULL;
    //     while (cur) {
    //         tmp = cur->next;
    //         cur->next = pre;
    //         pre = cur;
    //         cur = tmp;
    //     }
    //     return pre;
    // }

    // 24.两两交换链表中的结点
    // ListNode* swapPairs(ListNode* head) {
    //      ListNode *dummyhead = new ListNode(0);
    //      dummyhead->next = head;
    //      ListNode *cur = dummyhead, *cur1, *cur2;
    //      while (cur->next != NULL && cur->next->next != NULL) {
    //         cur1 = cur->next;
    //         cur2 = cur1->next;
    //         cur->next = cur2;
    //         cur1->next = cur2->next;
    //         cur2->next = cur1;
    //         cur = cur1;
    //      }
    //      return dummyhead->next;
    // }

    // 19.删除链表的倒数第N个结点
    // ListNode* removeNthFromEnd(ListNode* head, int n) {
    //     ListNode *dummyhead = new ListNode(0), *cur, *tmp;
    //     dummyhead->next = head;
    //     cur = dummyhead;
    //     int size = 0;
    //     while (cur->next != NULL) {
    //         cur = cur->next;
    //         size++;
    //     }
    //     int idx = size - n;
    //     cur = dummyhead;
    //     while (idx--) {
    //         cur = cur->next;
    //     }
    //     tmp = cur->next;
    //     cur->next = tmp->next;
    //     delete tmp;
    //    
    //     return dummyhead->next;
    // }

    // 面试题 02.07.链表相交
    // ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    //     int sizeA = 0, sizeB = 0, temp;
    //     ListNode *curA, *curB, *tmp;
    //     curA = headA;
    //     curB = headB;
    //     while (curA != NULL) {
    //         sizeA++;
    //         curA = curA->next;
    //     }
    //     while (curB != NULL) {
    //         sizeB++;
    //         curB = curB->next;
    //     }
    //     curA = headA;
    //     curB = headB;
    //     // 若B长于A，还是将A标志为较长的链表
    //     if (sizeB > sizeA) {
    //         tmp = curA;
    //         curA = curB;
    //         curB = tmp;
    //         temp = sizeA;
    //         sizeA = sizeB;
    //         sizeB = temp;
    //     }
    //     int skip = sizeA - sizeB;
    //     while (skip--) {
    //         curA = curA->next;
    //     }
    //     while (curA != NULL) {
    //         if (curA == curB) {
    //             return curA;
    //         }
    //         curA = curA->next;
    //         curB = curB->next;
    //     }
    //     return NULL;
    // }

    // 142.环形链表 II (一刷有参考)
    // ListNode *detectCycle(ListNode *head) {
    //     ListNode *fast = head, *slow = head;
    //     while (fast != NULL && fast->next != NULL) {
    //         fast = fast->next->next;
    //         slow = slow->next;
    //         // 快慢相遇
    //         if (slow == fast) {
    //             ListNode *idx1 = fast, *idx2 = head;
    //             while (idx1 != idx2) {
    //                 idx1 = idx1->next;
    //                 idx2 = idx2->next;
    //             }
    //             return idx2;       // 返回环的入口
    //         }
    //     }
    //     return NULL;
    // }

    // 234. 回文链表
    // bool isPalindrome(ListNode* head) {
    //     ListNode *dummyhead = new ListNode(0);
    //     vector<int> vec;
    //     dummyhead->next = head;
    //     int count = 0;
    //     ListNode *cur = dummyhead;
    //     while (cur->next != nullptr) {
    //         cur = cur->next;
    //         count++;
    //     }
    //     int times = (count + 1) / 2;
    //     cur = dummyhead;
    //     while (times--) {
    //         cur = cur->next;
    //         vec.push_back(cur->val);
    //     }
    //     for (int i = count / 2 - 1; i >= 0 ; i--) {
    //         cur = cur->next;
    //         if (cur->val != vec[i]) {
    //             return false;
    //         }
    //     }
    //     return true;
    // }

    // 143. 重排链表
    // void reorderList(ListNode* head) {
    //     // 用快慢指针找到中间结点位置
    //     ListNode* dummyhead = new ListNode(0);
    //     dummyhead->next = head;
    //     if (head->next == nullptr || head->next->next == nullptr) {
    //         return;
    //     }
    //     ListNode *slow = dummyhead, *fast = dummyhead;
    //     while (fast->next != nullptr && fast->next->next != nullptr) {
    //         slow = slow->next;
    //         fast = fast->next->next;
    //     }
    //     // 反转后半部分链表
    //     ListNode* reversed = reverseList(slow->next);
    //     slow->next = nullptr;
    //     // 交叉输出
    //     ListNode *cur1 = head, *cur2 = reversed;
    //     ListNode *tmp1, *tmp2;
    //     while (cur1 != nullptr) {
    //         tmp1 = cur1->next;
    //         tmp2 = cur2->next;
    //         cur1->next = cur2;
    //         if (tmp1 != nullptr) {
    //             cur2->next = tmp1;
    //         }
    //         cur1 = tmp1;
    //         cur2 = tmp2;
    //     }
    //     return;
    // }
    // // 反转链表
    // ListNode* reverseList(ListNode* head) {
    //     ListNode *pre = nullptr, *cur = head, *tmp;
    //     while (cur != nullptr) {
    //         tmp = cur->next;
    //         cur->next = pre;
    //         pre = cur;
    //         cur = tmp;
    //     }
    //     return pre;
    // }
};


// 707.设计链表 (一刷有参考)
// class MyLinkedList {
// public:
//     // 定义结构体
//     struct LinkedNode {
//         int val;
//         LinkedNode *next;
//         LinkedNode(int x) : val(x), next(nullptr) {}
//     };
//
//     // 构造函数：对链表的初始化
//     MyLinkedList() {
//         _dummyhead = new LinkedNode(0);     // 虚拟头结点
//         _size = 0;
//     }
//
//     int get(int index) {
//         if (index < 0 || index >= _size) {
//             return -1;
//         }
//         LinkedNode *cur = _dummyhead->next;
//         while (index--) {
//             cur = cur->next;
//         }
//         return cur->val;
//     }
//
//     void addAtHead(int val) {
//         LinkedNode *obj = new LinkedNode(val);
//         obj->next = _dummyhead->next;
//         _dummyhead->next = obj;
//         _size++;
//     }
//   
//     void addAtTail(int val) {
//         LinkedNode *obj = new LinkedNode(val), *cur = _dummyhead;
//         while (cur->next != NULL) {
//             cur = cur->next;
//         }
//         obj->next = cur->next;
//         cur->next = obj;
//         _size++;
//     }
//   
//     void addAtIndex(int index, int val) {
//         if (index > _size) {
//             return;
//         } else if (index < 0) {
//             addAtHead(val);
//             return;
//         }
//         LinkedNode *obj = new LinkedNode(val), *cur = _dummyhead;
//         while (index--) {
//             cur = cur->next;
//         }
//         obj->next = cur->next;
//         cur->next = obj;
//         _size++;
//         return;
//     }
//    
//     void deleteAtIndex(int index) {
//         if (index < 0 || index >= _size) {
//             return;
//         }
//         LinkedNode *cur = _dummyhead, *tmp;
//         while (index--) {
//             cur = cur->next;
//         }
//         tmp = cur->next;
//         cur->next = tmp->next;
//         delete tmp;
//         _size--;
//     }
//
// private:
//     LinkedNode *_dummyhead;
//     int _size;
// };


int main() {
    Solution solution;

    // 203.移除链表元素
    // vector<int> vec = {7,7,7,7};
    // ListNode* head = new ListNode(vec[vec.size()-1]);
    // for (int i = vec.size()-2; i >= 0; i--) {
    //     ListNode* tmp = new ListNode(vec[i], head);
    //     head = tmp;
    // }
    // ListNode* res = solution.removeElements(head, 6);
    // ListNode* cur = res;
    // while (cur) {
    //     cout<<cur->val<<" ";
    //     cur = cur->next;
    // }

    // 707.设计链表
    // MyLinkedList* obj = new MyLinkedList();
    // obj->addAtHead(1);
    // obj->addAtTail(3);
    // obj->addAtIndex(1,2);   //链表变为1-> 2-> 3
    // int res1 = obj->get(1);            //返回2
    // obj->deleteAtIndex(1);  //现在链表是1-> 3
    // int res2 = obj->get(1);            //返回3
    // cout<<res1<<" "<<res2;

    // 24.两两交换链表中的结点 / 19.删除链表的倒数第N个结点
    // vector<int> vec = {};
    // ListNode* head;
    // if (vec.size() == 0) {
    //     head = nullptr;
    // } else {
    //     head = new ListNode(vec[vec.size()-1]);
    // }
    // for (int i = vec.size()-2; i >= 0; i--) {
    //     ListNode* tmp = new ListNode(vec[i], head);
    //     head = tmp;
    // }
    // ListNode* res = solution.removeNthFromEnd(head, 0);
    // ListNode* cur = res;
    // while (cur) {
    //     cout<<cur->val<<" ";
    //     cur = cur->next;
    // }
}