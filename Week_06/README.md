# 学习笔记

动态规划(不是规划) [Dynamic Programming](https://en.wikipedia.org/wiki/Dynamic_programming)

"Simplifying a complicated problem by breaking it down into simpler sub-problems"(in a recursive manner)

Divide & Conquer + Optimal substructure(最优子结构)

## 关键点

和递归、分治没有本质区别，关键在于是否有**最优子结构**

共性： 重复子问题

差异性：最优子结构、中途淘汰次优解

## 实现关键点

1. 最优子结构 opt[n] = best_of(opt[n-1], opt[n-2], ...)

2. 存储中间状态: optp[i] (和分治的主要区别，分治把栈放在递归中)

3. 递推公式

实战例题

不同路径（Facebook、亚马逊、微软在半年内面试中考过）
不同路径 II （谷歌、美团、微软在半年内面试中考过）
最长公共子序列（字节跳动、谷歌、亚马逊在半年内面试中考过）
[MIT 动态规划课程最短路径算法](https://www.bilibili.com/video/av53233912?from=search&seid=2847395688604491997)
爬楼梯（阿里巴巴、腾讯、字节跳动在半年内面试常考）
三角形最小路径和（亚马逊、苹果、字节跳动在半年内面试考过）
三角形最小路径和高票回答： https://leetcode.com/problems/triangle/discuss/38735/Python-easy-to-understand-solutions-(top-down-bottom-up)
最大子序和（亚马逊、字节跳动在半年内面试常考）
乘积最大子数组（亚马逊、字节跳动、谷歌在半年内面试中考过）
零钱兑换（亚马逊在半年内面试中常考）
打家劫舍（字节跳动、谷歌、亚马逊在半年内面试中考过）
打家劫舍 II （字节跳动在半年内面试中考过）
买卖股票的最佳时机（亚马逊、字节跳动、Facebook 在半年内面试中常考）
买卖股票的最佳时机 II （亚马逊、字节跳动、微软在半年内面试中考过）
买卖股票的最佳时机 III （字节跳动在半年内面试中考过）
最佳买卖股票时机含冷冻期（谷歌、亚马逊在半年内面试中考过）
买卖股票的最佳时机 IV （谷歌、亚马逊、字节跳动在半年内面试中考过）
买卖股票的最佳时机含手续费
一个方法团灭 6 道股票问题

高级 DP 实战题目

完全平方数（亚马逊、谷歌在半年内面试中考过）
编辑距离 （重点）
跳跃游戏（亚马逊在半年内面试中考过）
跳跃游戏 II （亚马逊、华为字节跳动在半年内面试中考过）
不同路径（Facebook、亚马逊、微软在半年内面试中考过）
不同路径 II （谷歌、美团、微软在半年内面试中考过）
不同路径 III （谷歌在半年内面试中考过）
零钱兑换（亚马逊在半年内面试中常考）
零钱兑换 II （亚马逊、字节跳动在半年内面试中考过）

本周作业
中等
最小路径和（亚马逊、高盛集团、谷歌在半年内面试中考过）
解码方法（亚马逊、Facebook、字节跳动在半年内面试中考过）
最大正方形（华为、谷歌、字节跳动在半年内面试中考过）
任务调度器（Facebook 在半年内面试中常考）
回文子串（Facebook、苹果、字节跳动在半年内面试中考过）
困难
最长有效括号（字节跳动、亚马逊、微软在半年内面试中考过）
编辑距离（字节跳动、亚马逊、谷歌在半年内面试中考过）
矩形区域不超过 K 的最大数值和（谷歌在半年内面试中考过）
青蛙过河（亚马逊、苹果、字节跳动在半年内面试中考过）
分割数组的最大值（谷歌、亚马逊、Facebook 在半年内面试中考过）
学生出勤记录 II （谷歌在半年内面试中考过）
最小覆盖子串（Facebook 在半年内面试中常考）
戳气球（亚马逊在半年内面试中考过）
## 练习中的失误点

二维DP的起始边和列的处理方式，对于是否起始行列加行列处理尚不到位。

[1143. Longest Common Subsequence](https://leetcode-cn.com/problems/longest-common-subsequence/)

```cpp
vector<vector<short>> m(text1.size() + 1, vector<short>(text2.size() + 1));
```

[64. Minimum Path Sum](https://leetcode-cn.com/problems/minimum-path-sum/)
```cpp
int dp_matrix[grid.size()][grid[0].size()];

dp_matrix[0][0] = grid[0][0];
for (int i = 1; i < grid.size(); i++) dp_matrix[i][0] = dp_matrix[i-1][0]+grid[i][0];
for (int j = 1; j < grid[0].size(); j++) dp_matrix[0][j] = dp_matrix[0][j-1]+grid[0][j]; 
```

[363. Max Sum of Rectangle No Larger Than K](https://leetcode-cn.com/problems/max-sum-of-rectangle-no-larger-than-k/)
```cpp
int DP[rows+1][cols+1];
for (int i = 0; i < rows + 1; i++) DP[i][0] = 0;
for (int j = 0; j < cols + 1; j++) DP[0][j] = 0;
for (int i = 1 ; i < rows + 1; i++){
    for (int j = 1 ; j < cols + 1; j++)DP[i][j] = DP[i-1][j] + DP[i][j-1] - DP[i-1][j-1] + matrix[i-1][j-1];}

```