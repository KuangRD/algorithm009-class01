# 学习笔记

## 泛型递归、树的递归

树的解法一般都是递归（Recursive）

1. 节点的定义（树结构的定义为递归）

2. 重复性（自相似性）

思维要点 

1. 抵制人肉递归
2. 找最近重复性
3. 数学归纳法思维

### 模板
```py
# Python
def recursion(level, param1, param2, ...): 
    # recursion terminator 
    if level > MAX_LEVEL: 
	   process_result 
	   return 
    # process logic in current level 
    process(level, data...) 
    # drill down 
    self.recursion(level + 1, p1, ...) 
    # reverse the current level status if needed
```

```C++
// C/C++
void recursion(int level, int param) { 
  // recursion terminator
  if (level > MAX_LEVEL) { 
    // process result 
    return ; 
  }

  // process current logic 
  process(level, param);

  // drill down 
  recursion(level + 1, param);

  // reverse the current level status if needed
}
```
实战题目
爬楼梯（阿里巴巴、腾讯、字节跳动在半年内面试常考）
括号生成 (字节跳动在半年内面试中考过)
翻转二叉树 (谷歌、字节跳动、Facebook 在半年内面试中考过)
验证二叉搜索树（亚马逊、微软、Facebook 在半年内面试中考过）
二叉树的最大深度（亚马逊、微软、字节跳动在半年内面试中考过）
二叉树的最小深度（Facebook、字节跳动、谷歌在半年内面试中考过）
二叉树的序列化与反序列化（Facebook、亚马逊在半年内面试常考）

## 分治、回溯 Divide & Conquer, Backtracing

模板和泛型递归基本一致,多了一个结果组装。

```py
# Python
def divide_conquer(problem, param1, param2, ...): 
  # recursion terminator 
  if problem is None: 
	print_result 
	return 

  # prepare data 
  data = prepare_data(problem) 
  subproblems = split_problem(problem, data) 

  # conquer subproblems 
  subresult1 = self.divide_conquer(subproblems[0], p1, ...) 
  subresult2 = self.divide_conquer(subproblems[1], p1, ...) 
  subresult3 = self.divide_conquer(subproblems[2], p1, ...) 
  …

  # process and generate the final result 
  result = process_result(subresult1, subresult2, subresult3, …)
	
  # revert the current level states
```

```C++

int divide_conquer(Problem *problem, int params) {
  // recursion terminator
  if (problem == nullptr) {
    process_result
    return return_result;
  } 

  // process current problem
  subproblems = split_problem(problem, data)
  subresult1 = divide_conquer(subproblem[0], p1)
  subresult2 = divide_conquer(subproblem[1], p1)
  subresult3 = divide_conquer(subproblem[2], p1)
  ...

  // merge
  result = process_result(subresult1, subresult2, subresult3)
  // revert the current level status
 
  return 0;
}
```

回溯 Backtracing

典型应用 八皇后 数独

实战题目
Pow(x, n) （Facebook 在半年内面试常考）
子集（Facebook、字节跳动、亚马逊在半年内面试中考过）
[多数元素](https://leetcode-cn.com/problems/majority-element/description/)
电话号码的字母组合（亚马逊在半年内面试常考）
N 皇后（字节跳动、苹果、谷歌在半年内面试中考过）

[牛顿迭代法快速寻找平方根](http://www.matrix67.com/blog/archives/361)
[牛顿迭代法代码](http://www.voidcn.com/article/p-eudisdmk-zm.html)

Homework

二叉树的最近公共祖先（Facebook 在半年内面试常考）
从前序与中序遍历序列构造二叉树（字节跳动、亚马逊、微软在半年内面试中考过）
组合（微软、亚马逊、谷歌在半年内面试中考过）
全排列（字节跳动在半年内面试常考）
全排列 II （亚马逊、字节跳动、Facebook 在半年内面试中考过

![alt test][image1]


[//]: # (Image References)

[image1]: ./pic/week3_3ac.png