# 学习笔记

## 数组、链表、跳表的基本实现和特性

### Array

[C++ Array Source Code(GNU)](https://gcc.gnu.org/onlinedocs/gcc-4.6.3/libstdc++/api/a00752_source.html)

[开源SGI STL注释](https://github.com/steveLauwh/SGI-STL)

侯捷SGI STL源码注释（尚未找到）

### Linked List

```cpp
// LeetCode Version
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };

 
class Node { 
public: 
    int data; 
    Node* next; 
}; 
```
## 栈、队列、优先队列、双端队列

### Stack

### Queue

### PriorityQueue

### Others

[python heapq](https://docs.python.org/3.8/library/heapq.html)

[Python High-performance container datatypes](https://docs.python.org/3.8/library/collections.html)


## HomeWork


### 简单：

* 用 add first 或 add last 这套新的 API 改写 Deque 的代码

* 分析 Queue 和 Priority Queue 的源码

* 删除排序数组中的重复项（Facebook、字节跳动、微软在半年内面试中考过）

* 旋转数组（微软、亚马逊、PayPal 在半年内面试中考过）

* 合并两个有序链表（亚马逊、字节跳动在半年内面试常考）

* 合并两个有序数组（Facebook 在半年内面试常考）

* 两数之和（亚马逊、字节跳动、谷歌、Facebook、苹果、微软在半年内面试中高频常考）

* 移动零（Facebook、亚马逊、苹果在半年内面试中考过）

* 加一（谷歌、字节跳动、Facebook 在半年内面试中考过）
### 中等：

* 设计循环双端队列（Facebook 在 1 年内面试中考过）

### 困难：

* 接雨水（亚马逊、字节跳动、高盛集团、Facebook 在半年内面试常考）

## Practice Summary
![alt test][image1]


[//]: # (Image References)

[image1]: ./pic/3ac.png