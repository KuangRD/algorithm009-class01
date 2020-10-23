# Week2学习笔记
### Weekly Practice
![alt test][image1]

### Knownledge Point

#### 1. Hash表

HashMap基于hashing原理，我们通过put()和get()方法储存和获取对象。当我们将键值对传递给put()方法时，它调用键对象的hashCode()方法来计算hashcode，让后找到bucket位置来储存值对象。当获取对象时，通过键对象的equals()方法找到正确的键值对，然后返回值对象。HashMap使用LinkedList来解决碰撞问题，当发生碰撞了，对象将会储存在LinkedList的下一个节点中。 HashMap在每个LinkedList节点中储存键值对对象。

应用： Set Map （还没看STL 源码（侯捷 书））
Hash Function写的不好，会导致hash碰撞（Hash Collisions），常用解决方式 冲突处写成链表 (拉链式解决冲突法)

#### 2. Tree

暂时没什么讲的，练习（递归+迭代法）

N叉树
```cpp
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
```

#### 3. Heap

根节点最大和最小，熟悉实现。

查找 操作必为 theta(1)的复杂度

删除，队尾元素替换到顶部，再依次向上调整(HeapifyDown) 复杂度最差O(logN)

插入， 插入堆的队尾，再依次向上调整(HeapifyUP) 复杂度最差O(logN)

二叉堆（通过完全二叉树实现）性能最差，但是实现简单；Strict Fibonacci(多叉树实现)性能最好。

二叉堆

* 是完全二叉树，一般通过数组实现.假设第一个元素索引为0，索引i的左儿子节点索引（2i+1），右（2i+2），父（floor(i-1)/2）；

* 树中任意节点大于等于子节点。



维基百科：堆（Heap）
堆的实现代码： https://shimo.im/docs/Lw86vJzOGOMpWZz2/

[HeapSort](https://www.geeksforgeeks.org/heap-sort/)

应用： Priority Queue

#### 4. 图 Graph

V - vertex:点
1, 度 degree 入度和出度
2, 点与点之间，连通与否

E - Edge: 边

## HomeWork 

* 写一个关于 HashMap 的小总结。

* 有效的字母异位词（亚马逊、Facebook、谷歌在半年内面试中考过）

* 两数之和（近半年内，亚马逊考查此题达到 216 次、字节跳动 147 次、谷歌 104 次，Facebook、苹果、微软、腾讯也在近半年内面试常考）
* N 叉树的前序遍历（亚马逊在半年内面试中考过）

* HeapSort ：自学 https://www.geeksforgeeks.org/heap-sort/
### 中等：
* 字母异位词分组（亚马逊在半年内面试中常考）

* 二叉树的中序遍历（亚马逊、字节跳动、微软在半年内面试中考过）

* 二叉树的前序遍历（字节跳动、谷歌、腾讯在半年内面试中考过）

* N 叉树的层序遍历（亚马逊在半年内面试中考过）

* 丑数（字节跳动在半年内面试中考过）

* 前 K 个高频元素（亚马逊在半年内面试中常考）

[//]: # (Image References)

[image1]: ./pic/week2_3ac.png