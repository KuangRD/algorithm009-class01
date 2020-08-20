# 学习笔记


## 字典树和并查集

### 字典树（Tire）
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

## Advanced Search

### 剪枝

终止不必要的、注定失败的、次优的搜索

### 双向BFS

个人认为，速度好于标准的A*(Admissible heuristic带来的估计误差), 但是搜索空间大于A*。

A*的启发函数大于真实值后，速度加快，但是可能不是最优解。

双向BFS的两端都是精确的COST。

### A*

老生常谈的算法了，注意A*的变形。（heuristic策略调整和JPS等方案） tie breaker

## 红黑树 AVL

二叉搜索树限制了子树深度。