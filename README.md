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

`s.substr(l, r)` 提取s字符串从l到r的片段

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

18、递归转迭代通用方法
https://leetcode.cn/circle/article/fOudRh/

19、可以用回溯法解决的问题
• 组合问题：N个数里面按一定规则找出k个数的集合
• 切割问题：一个字符串按一定规则有几种切割方式
• 子集问题：一个N个数的集合里有多少符合条件的子集
• 排列问题：N个数按一定规则全排列，有几种排列方式
• 棋盘问题：N皇后，解数独等等

20、背包/动规五部曲
1. 确定dp数组（dp table）以及下标的含义
2. 确定递推公式
3. dp数组如何初始化
4. 确定遍历顺序
5. 举例推导dp数组

21、01背包一维写法
dp[j]表示容量为j的背包可放入物品最大价值
'''
for(int i = 0; i < weight.size(); i++) { // 遍历物品
    for(int j = bagWeight; j >= weight[i]; j--) { // 遍历背包容量
        dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);

    }
}
'''
要倒序的原因：保证每个物品只被放进去一次
只能先遍历物品后遍历背包的原因：如果遍历背包容量放在上一层，那么每个dp[j]就只会放入一个物品，即：背包里只放入了一个物品。

22、在求装满01背包有几种方法的情况下，递推公式一般为：
```dp[j] += dp[j - nums[i]];```

23、求背包组合数问题：外层for遍历物品，内层for遍历背包；  
求背包排列数问题：外层for遍历背包，内层for遍历物品。  
完全背包相较于01背包的区别在于物品可以重复使用，代码（一维数组）层面上的体现为遍历背包时可以从前往后遍历。

24、线段树？  
这个分治方法类似于「线段树求解最长公共上升子序列问题」的 pushUp 操作。 也许读者还没有接触过线段树，没有关系，方法二的内容假设你没有任何线段树的基础。当然，如果读者有兴趣的话，推荐阅读线段树区间合并法解决多次询问的「区间最长连续上升序列问题」和「区间最大子段和问题」，还是非常有趣的。
链接：https://leetcode.cn/problems/maximum-subarray/solutions/228009/zui-da-zi-xu-he-by-leetcode-solution/

25、股票类问题一般定义一个二维数组dp[i][j]，i表示第i天的状态，j = {0, 1}，分别表示第i天处于持有股票状态/不持有股票状态

26、单调栈  
通常是一维数组，要寻找任一个元素的右边或者左边第一个比自己大或者小的元素的位置，此时我们就要想到可以用单调栈了。

27、环形链表：用快慢指针法判定

28、哈希结构对比

| 集合               | 底层实现 | 是否有序 | 是否可重复 | 查询效率 | 增删效率 |
| ------------------ | -------- | -------- | ---------- | -------- | -------- |
| std::set           | 红黑树   | 有序     | 否         | O(logn)  | O(logn)  |
| std::multiset      | 红黑树   | 有序     | 是         | O(logn)  | O(logn)  |
| std::unordered_set | 哈希表   | 无序     | 否         | O(1)     | O(1)     |

| 映射               | 底层实现 | 是否有序 | 是否可重复 | 查询效率 | 增删效率 |
| ------------------ | -------- | -------- | ---------- | -------- | -------- |
| std::map           | 红黑树   | 有序     | 否         | O(logn)  | O(logn)  |
| std::multimap      | 红黑树   | 有序     | 是         | O(logn)  | O(logn)  |
| std::unordered_map | 哈希表   | 无序     | 否         | O(1)     | O(1)     |