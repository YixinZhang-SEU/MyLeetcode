# MyLeetcode

## 待解答疑问
**1. poj中二叉树的输入问题？**

## 笔记
1、注意数组的范围等边界条件，**容器可能为空**

2、在vector不同位置插入元素

```c++
vector<int> res;
// vector迭代器
vector<int>::iterator it = res.begin();
// 首部添加元素
res.insert(res.begin(), element);

//p.s.循环时需要把迭代器放在循环内部，因为迭代器会随着insert或push操作而改变
```
3、二维vector
```c++
// 构建二维vector，以及为每一维赋长度
vector<vector<int> > res(n);
for (int i = 0; i < n; i++) {
    res[i].resize(n);
}

// 二维数组
int[][] res = new int[n][n];
```

4、定义链表节点的方式

```c++
// 单链表
struct ListNode {
    int val;  // 节点上存储的元素
    ListNode *next;  // 指向下一个节点的指针
    ListNode(int x) : val(x), next(NULL) {}  // 节点的构造函数
};
// 初始化
ListNode* head = new ListNode(5);

// 若不自定义构造函数的话，则在初始化时无法直接给变量赋值
ListNode* head = new ListNode();
head->val = 5;

// C++下删除节点后注意还需要从内存中删除对应空间；Java、Python不用管
// 问：poj的链表如何初始化？
```

5、哈希表
当我们要使用集合来解决哈希问题的时候，优先使用`unordered_set`，因为它的查询和增删效率是最优的，如果需要集合是有序的，那么就用`set`，如果要求不仅有序还要有重复数据的话，那么就用`multiset`。
`unordered_set::find()`函数是C++ STL中的内置函数，用于在容器中搜索元素。如果找到指定元素，它返回元素的迭代器，如果找不到指定元素，则返回指向`unordered_set::end()`的迭代器。

6、数组、字符串等初始化
```c++
int a[5];           //元素默认为0
int b[5] = {1, 2};  //1, 2, 0, 0, 0
string c[5] = {"a", "b"};   //"a", "b", "", "", ""
int a[5]{};     //即使是局部变量也会被初始化

//遍历
for (int a : b)  // b为数组，意思是将数组b中的元素一个个赋值给int a
```

7、可以利用快慢指针法找出循环，即：快指针每次走两步，慢指针每次走一步，当二者相等时则为一个循环周期。

8、unordered_map

```c++
//定义
unordered_map<int,int> map;
//插入
map.insert(pair<int,int>(v1,v2));
//迭代器
unordered_map<int,int>::iterator iter;
//find方法
iter = map.find(value);
if (iter == map.end()) || if(iter != map.end());
//取值
iter->first || iter->second;

```

9、string相关函数
`reverse`函数 [#include<algorithm>]
    `reverse`函数用于反转 [first, last)范围内的顺序。（注意：左闭右开）
    `reverse()`函数没有返回值。

 `resize`函数
    用于重定义string长度
    `s.resize(s.size() + n)`

10、KMP算法
![image-20220812145356571](README.assets/image-20220812145356571.png)


11、string 转 int 转 string

```c++
string s = "12";
int a = atoi(s.c_str());    // string 转 int
s_ = to_string(a);          // int 转 string
```

12、单调队列
即单调递减或单调递增的队列
以单调递减队列为例：
    设计单调队列的时候，pop，和push操作要保持如下规则：
    1. pop(value)：如果窗口移除的元素value等于单调队列的出口元素，那么队列弹出元素，否则不用任何操作
    2. push(value)：如果push的元素value大于入口元素的数值，那么就将队列入口的元素弹出，直到push元素的数值小于等于队列入口元素的数值为止
用deque（双向队列）实现单调队列

13、优先级队列 priority_queue
大根堆、小根堆
```c++
#include<queue>

// 定义结构体，使用运算符重载，自定义优先级1
struct cmp1 {
    bool operator()(const int& a, const int& b) {
        return a > b;       // 小根堆；<为大根堆
    }
}
// 自定义优先级2
struct num1 {
    int x;
    bool operator < (const number1& a) const {
        return x > a.x;     // 小根堆
    }
}

// 初始化
// 默认的优先级构造队列
priority_queue<int> que;
// 小根堆
priority_queue<int, vector<int>, cmp1> que1;
// 另一种小根堆
priority_queue<int, vector<int>, greater<int> > que3;   // less<int>
// 另另一种小根堆
priority_queue<number1> que5;
```

14、双向队列 deque
```c++
deque<int> dq;
dq.empty();
dq.size();
dq.max_size();
dq.front();
dq.back();

dq.push_front();
dq.push_back();
dq.pop_front();
dq.pop_back();
```

15、c++精度控制
```c++
#include<iomanip>
// 预设宽度
cout<<setw(5)<<255;
cout<<setw(5)<<setfill('@')<<255;
// 将数字转为 n进制
cout<<setbase(8)<<255;
// 控制小数点后 n位
cout<<setprecision(n)<<255;
```

16、morris遍历二叉树
https://zhuanlan.zhihu.com/p/101321696
https://blog.csdn.net/weixin_44337241/article/details/123868744

17、vector底层是用数组实现，insert效率低。改进：list，底层是链表实现。
```c++
list<vector<int> > que;
int idx = 10;
std::list<vector<int> >::iterator it = que.begin();
while(idx--) {
    it++;
}
que.inser(it, value);

vector<vector<int> > res = vector<vector<int> >(que.begin(), que.end());
```