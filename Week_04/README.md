# 学习笔记

## 深度优先搜索、广度优先搜索的实现和特性

优先级优先搜索（启发式搜索）

DFS模板

递归写法 
```py
visited = set() 

def dfs(node, visited):
    if node in visited: # terminator
    	# already visited 
    	return 

	visited.add(node) 

	# process current node here. 
	...
	for next_node in node.children(): 
		if next_node not in visited: 
			dfs(next_node, visited)
```

```c++
map<int, int> visited;

void dfs(Node* root) {
  // terminator
  if (!root) return ;

  if (visited.count(root->val)) {
    // already visited
    return ;
  }

  visited[root->val] = 1;

  // process current node here. 
  // ...
  for (int i = 0; i < root->children.size(); ++i) {
    dfs(root->children[i]);
  }
  return ;
}
```

非递归写法
```py
def DFS(self, tree): 

	if tree.root is None: 
		return [] 

	visited, stack = [], [tree.root]

	while stack: 
		node = stack.pop() 
		visited.add(node)

		process (node) 
		nodes = generate_related_nodes(node) 
		stack.push(nodes) 

	# other processing work 
	...
```

```C++
void dfs(Node* root) {
  map<int, int> visited;
  if(!root) return ;

  stack<Node*> stackNode;
  stackNode.push(root);

  while (!stackNode.empty()) {
    Node* node = stackNode.top();
    stackNode.pop();
    if (visited.count(node->val)) continue;
    visited[node->val] = 1;


    for (int i = node->children.size() - 1; i >= 0; --i) {
        stackNode.push(node->children[i]);
    }
  }

  return ;
}
```

BFS模板
```py
def BFS(graph, start, end):
    visited = set()
	queue = [] 
	queue.append([start]) 
	while queue: 
		node = queue.pop() 
		visited.add(node)
		process(node) 
		nodes = generate_related_nodes(node) 
		queue.push(nodes)
	# other processing work 
	...
```

```C++
void bfs(Node* root) {
  map<int, int> visited;
  if(!root) return ;

  queue<Node*> queueNode;
  queueNode.push(root);

  while (!queueNode.empty()) {
    Node* node = queueNode.top();
    queueNode.pop();
    if (visited.count(node->val)) continue;
    visited[node->val] = 1;

    for (int i = 0; i < node->children.size(); ++i) {
        queueNode.push(node->children[i]);
    }
  }

  return ;
}
```

实战题目
二叉树的层序遍历（字节跳动、亚马逊、微软在半年内面试中考过）
最小基因变化
括号生成（字节跳动、亚马逊、Facebook 在半年内面试中考过）
在每个树行中找最大值（微软、亚马逊、Facebook 在半年内面试中考过）

贪心算法 Greedy

贪心: 当下做局部最优， 不回退
回溯: 能够回退
DP: 最优判断+回退。（保留之前的最优解，并根据之前最优解选当前结果）

Coin Change 硬币有整除关系时可以贪心。

贪心是最优解的场景，子问题的最优解能够递推到最终问题的最优解。这种子问题最优解称为最优子结构。

https://zh.wikipedia.org/wiki/%E5%8A%A8%E6%80%81%E8%A7%84%E5%88%92

## 二分查找

前提：
1, 目标函数单调性；
2, 存在上下界；
3, 能够通过索引访问(index accessible)

模板
```py
# Python
left, right = 0, len(array) - 1 
while left <= right: 
	  mid = (left + right) / 2 
	  if array[mid] == target: 
		    # find the target!! 
		    break or return result 
	  elif array[mid] < target: 
		    left = mid + 1 
	  else: 
		    right = mid - 1
```

```C++
int binarySearch(const vector<int>& nums, int target) {
	int left = 0, right = (int)nums.size()-1;
	
	while (left <= right) {
		int mid = left + (right - left)/ 2;
		if (nums[mid] == target) return mid;
		else if (nums[mid] < target) left = mid + 1;
		else right = mid - 1;
	}
	
	return -1;
}
```

牛顿迭代法

ref [Fast InvSqrt() 扩展阅读](https://www.beyond3d.com/content/articles/8/)
```C++
long r = x;
while (r*r > x) {
    r = (r + x/r) / 2;
return r;
} 
```
实战题目
x 的平方根（字节跳动、微软、亚马逊在半年内面试中考过）
有效的完全平方数（亚马逊在半年内面试中考过）

Homework
单词接龙（亚马逊在半年内面试常考）
单词接龙 II （微软、亚马逊、Facebook 在半年内面试中考过）
岛屿数量（近半年内，亚马逊在面试中考查此题达到 350 次）
扫雷游戏（亚马逊、Facebook 在半年内面试中考过）

柠檬水找零（亚马逊在半年内面试中考过）
买卖股票的最佳时机 II （亚马逊、字节跳动、微软在半年内面试中考过）
分发饼干（亚马逊在半年内面试中考过）
模拟行走机器人
跳跃游戏 （亚马逊、华为、Facebook 在半年内面试中考过）
跳跃游戏 II （亚马逊、华为、字节跳动在半年内面试中考过）

搜索旋转排序数组（Facebook、字节跳动、亚马逊在半年内面试常考）
搜索二维矩阵（亚马逊、微软、Facebook 在半年内面试中考过）
寻找旋转排序数组中的最小值（亚马逊、微软、字节跳动在半年内面试中考过）
使用二分查找，寻找一个半有序数组 [4, 5, 6, 7, 0, 1, 2] 中间无序的地方
说明：同学们可以将自己的思路、代码写在学习总结中

![alt test][image1]


[//]: # (Image References)

[image1]: ./pic/week4_3ac.png