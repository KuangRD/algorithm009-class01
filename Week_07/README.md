# 学习笔记


## 字典树和并查集

### 字典树（Trie）
也即单词查找树或者键树，是一种树形结构。典型应用是用于统计和排序大量字符串（但不限于字符串），所以经常被搜索引擎系统用于文本词频统计。

优点：最大限度地减少无谓的字符串比较，查询效率比哈希表高。

基本性质

1. 结点本身不存完整单词；

2. 从根结点到某一结点，路径上经过的字符连接起来，为该节点对应的字符串；

3. 每个结点的所有子结点路径代表的字符都不相同。


课程模板
```py
class Trie(object):
  
	def __init__(self): 
		self.root = {} 
		self.end_of_word = "#" 
 
	def insert(self, word): 
		node = self.root 
		for char in word: 
			node = node.setdefault(char, {}) 
		node[self.end_of_word] = self.end_of_word 
 
	def search(self, word): 
		node = self.root 
		for char in word: 
			if char not in node: 
				return False 
			node = node[char] 
		return self.end_of_word in node 
 
	def startsWith(self, prefix): 
		node = self.root 
		for char in prefix: 
			if char not in node: 
				return False 
			node = node[char] 
		return True
```

```C++
class Trie {
    struct TrieNode {
        map<char, TrieNode*>child_table;
        int end;
        TrieNode(): end(0) {}
    };
        
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode *curr = root;
        for (int i = 0; i < word.size(); i++) {
            if (curr->child_table.count(word[i]) == 0)
                curr->child_table[word[i]] = new TrieNode();
                
            curr = curr->child_table[word[i]];                
        }
        curr->end = 1;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        return find(word, 1);
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        return find(prefix, 0);
    }
private:
    TrieNode* root;
    bool find(string s, int exact_match) {
        TrieNode *curr = root;
        for (int i = 0; i < s.size(); i++) {
            if (curr->child_table.count(s[i]) == 0)
                return false;
            else
                curr = curr->child_table[s[i]];
        }
        
        if (exact_match)
            return (curr->end) ? true : false;
        else
            return true;
    }
};
```

前缀树的C++实现(待进一步优化)
[208. Implement Trie (Prefix Tree)](https://leetcode-cn.com/problems/implement-trie-prefix-tree/)

```cpp
class TrieNode {
public:
    bool isEnd;
    TrieNode* children[26];

    TrieNode() {
        isEnd = false;
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
    }
};
class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* cur = root;

        for (int i = 0; i < word.size(); i++) {
            int alphabet_idx = word[i] - 'a';
            if (!cur->children[alphabet_idx]) cur->children[alphabet_idx] = new TrieNode();
            cur = cur->children[alphabet_idx];
        }
        cur->isEnd = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* cur = root;

        for (int i = 0; i < word.size(); i++) {
            int alphabet_idx = word[i] - 'a';
            if (!cur->children[alphabet_idx]) return false;
            cur = cur->children[alphabet_idx];
        }
        return cur->isEnd;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* cur = root;

        for (int i = 0; i < prefix.size(); i++) {
            int alphabet_idx = prefix[i] - 'a';
            if (!cur->children[alphabet_idx]) return false;
            cur = cur->children[alphabet_idx];
        }
        return true;
    }
private:
    TrieNode* root;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
```

使用Tire做[单词搜索2](https://leetcode-cn.com/problems/word-search-ii/)的时间复杂度

```
O(mn * 26^k *4)? mn 长宽， 4联通，最大26种后续可能性，单词最长为k
```


### 并查集（Disjoint Set）

* 每类元素均维护一个代表元素；

* 每个元素的都直接或间接指向代表元素，代表元素的代表元素指向它本身；

* 支持创建 查询 插入 合并 路径压缩等操作

基于课程中Java模板改写C++版本如下

```cpp
class UnionFind { 

private:    
	int* parent; 

public:
    int count = 0;  
    UnionFind(int n) { 
		count = n; 
		parent = new int[n]; 
		for (int i = 0; i < n; i++) parent[i] = i;
	} 
	
    int find(int p) { 
		while (p != parent[p]) p = parent[p]; 
		return p; 
	}
	
    void union_set(int p, int q) { 
		int rootP = find(p); 
		int rootQ = find(q); 
		if (rootP == rootQ) return; 
		parent[rootP] = rootQ; 
		count--;
    }
};

```

```py

def init(p): 
	# for i = 0 .. n: p[i] = i; 
	p = [i for i in range(n)] 
 
def union(self, p, i, j): 
	p1 = self.parent(p, i) 
	p2 = self.parent(p, j) 
	p[p1] = p2 
 
def parent(self, p, i): 
	root = i 
	while p[root] != root: 
		root = p[root] 
	while p[i] != i: # 路径压缩 ?
		x = i; i = p[i]; p[x] = root 
	return root
```

```C++
class UnionFind {
public:
    UnionFind(vector<vector<char>>& grid) {
        count = 0;
        int m = grid.size();
        int n = grid[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '1') {
                    parent.push_back(i * n + j);
                    ++count;
                }
                else {
                    parent.push_back(-1);
                }
                rank.push_back(0);
            }
        }
    }

//递归
    int find(int i) {
        if (parent[i] != i) {
            parent[i] = find(parent[i]);
        }
        return parent[i];
    }


    void unite(int x, int y) {
        int rootx = find(x);
        int rooty = find(y);
        if (rootx != rooty) {
            if (rank[rootx] < rank[rooty]) {
                swap(rootx, rooty);
            }
            parent[rooty] = rootx;
            if (rank[rootx] == rank[rooty]) rank[rootx] += 1;
            --count;
        }
    }


    int getCount() const {
        return count;
    }


private:
    vector<int> parent;
    vector<int> rank;
    int count;
};

```

## Advanced Search

[AlphaZero Explained](https://nikcheerla.github.io/deeplearningschool/2018/01/01/AlphaZero-Explained/)

[棋类复杂度](https://en.wikipedia.org/wiki/Game_complexity)
### 剪枝

终止不必要的、注定失败的、次优的搜索

### 双向BFS

个人认为，速度好于标准的A*(Admissible heuristic带来的估计误差), 但是搜索空间大于A*。

A*的启发函数大于真实值后，速度加快，但是可能不是最优解。

双向BFS的两端都是精确的COST。

### A*

老生常谈的算法了，注意A*的变形。（heuristic策略调整和JPS等方案） tie breaker

connections高性能python数据结构库

[相似度测量方法](https://dataaspirant.com/five-most-popular-similarity-measures-implementation-in-python/)

[二进制矩阵中的最短路径的 A* 解法](https://leetcode.com/problems/shortest-path-in-binary-matrix/discuss/313347/A*-search-in-Python)

[8 puzzles 解法比较](https://zxi.mytechroad.com/blog/searching/8-puzzles-bidirectional-astar-vs-bidirectional-bfs/)

```py
# Python
def AstarSearch(graph, start, end):
	pq = collections.priority_queue() # 优先级 —> 估价函数
	pq.append([start]) 
	visited.add(start)
	while pq: 
		node = pq.pop() # can we add more intelligence here ?
		visited.add(node)
		process(node) 
		nodes = generate_related_nodes(node) 
   unvisited = [node for node in nodes if node not in visited]
		pq.push(unvisited)
```

```C++
class Node {
public:
    int x;
    int y;
    bool operator< (const Node &A) {
        // 
    }
};

void generate_related_nodes(Node &node) {
    // 
}

void process(Node &node) {
    // 
}

void AstarSearch(vector<vector<int>>& graph, Node& start, Node& end) {
    vector<vector<bool> > visited(graph.size(), vector<bool>(graph[0].size(), false));
    priority_queue<Node> q;
    q.push(start);

    while (!q.empty()) {
        Node cur = q.top();
        q.pop();
        visited[cur.x][cur.y] = true;


        process(node);
        vector<Node> nodes = generate_related_nodes(node) 
        for (auto node : nodes) {
            if (!visited[node.x][node.y]) q.push(node);
        }
    }

    return ;
}

```

## 红黑树 AVL

二叉搜索树限制了子树深度。

BST增删查找操作的 实现

[平衡树](https://en.wikipedia.org/wiki/Self-balancing_binary_search_tree)

面试重点 红黑树 AVL

掌握重点 2-3 tree, AVL tree, B-tree, Red-black tree

### AVL

平衡二叉树

* Balance Factor(平衡因子)

* 每个结点记录左右子树高度差(平衡因子)

* 四种旋转操作 左旋 优旋 左右旋 右左旋, 来保证增删查改后的平衡因子

不足：结点需要存储平衡因子，且调整次数频繁。

### 红黑树

近似平衡二叉树，任何结点左右子树高度差小于两倍。

* 结点颜色红或黑

* 根结点是黑

* 叶节点(NIL结点，空结点)是黑色的。

* 不能有相邻接的两个红色结点

* 任一结点到其每个叶子的所有路径都包含相同数目的黑色结点。

后两条保证高度差小于两倍。

对比见课件

![alt test][image1]


[//]: # (Image References)

[image1]: ./pic/snip.png

实战题目

实现 Trie (前缀树) （亚马逊、微软、谷歌在半年内面试中考过）
单词搜索 II （亚马逊、微软、苹果在半年内面试中考过）
分析单词搜索 2 用 Tire 树方式实现的时间复杂度，请同学们提交在学习总结中。


朋友圈（亚马逊、Facebook、字节跳动在半年内面试中考过）
岛屿数量（近半年内，亚马逊在面试中考查此题达到 361 次）
被围绕的区域（亚马逊、eBay、谷歌在半年内面试中考过）

爬楼梯（阿里巴巴、腾讯、字节跳动在半年内面试常考）
括号生成（亚马逊、Facebook、字节跳动在半年内面试中考过）
N 皇后（亚马逊、苹果、字节跳动在半年内面试中考过）
有效的数独（亚马逊、苹果、微软在半年内面试中考过）
解数独（亚马逊、华为、微软在半年内面试中考过）

单词接龙（亚马逊、Facebook、谷歌在半年内面试中考过）
最小基因变化（谷歌、Twitter、腾讯在半年内面试中考过）

二进制矩阵中的最短路径（亚马逊、字节跳动、Facebook 在半年内面试中考过）
滑动谜题（微软、谷歌、Facebook 在半年内面试中考过）
解数独（微软、华为、亚马逊在半年内面试中考过）

Homework

本周作业
简单
爬楼梯（阿里巴巴、腾讯、字节跳动在半年内面试常考）
中等
实现 Trie (前缀树) （亚马逊、微软、谷歌在半年内面试中考过）
朋友圈（亚马逊、Facebook、字节跳动在半年内面试中考过）
岛屿数量（近半年内，亚马逊在面试中考查此题达到 361 次）
被围绕的区域（亚马逊、eBay、谷歌在半年内面试中考过）
有效的数独（亚马逊、苹果、微软在半年内面试中考过）
括号生成（亚马逊、Facebook、字节跳动在半年内面试中考过）
单词接龙（亚马逊、Facebook、谷歌在半年内面试中考过）
最小基因变化（谷歌、Twitter、腾讯在半年内面试中考过）
困难
单词搜索 II （亚马逊、微软、苹果在半年内面试中考过）
N 皇后（亚马逊、苹果、字节跳动在半年内面试中考过）
解数独（亚马逊、华为、微软在半年内面试中考过）