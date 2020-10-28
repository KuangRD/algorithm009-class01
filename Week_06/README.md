# 学习笔记

动态规划(不是规划) [Dynamic Programming](https://en.wikipedia.org/wiki/Dynamic_programming)

"Simplifying a complicated problem by breaking it down into simpler sub-problems"(in a recursive manner)

Divide & Conquer + Optimal substructure(最优子结构)

## 关键点

和递归、分治没有本质区别，关键在于是否有**最优子结构**

共性： 重复子问题

差异性：最优子结构、中途淘汰次优解

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