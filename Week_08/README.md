# 学习笔记

## 位运算

* 奇偶判断
X%2 ----> (x&1) == 1 ? 0

* 除2
x >> 1

* 清零最低位的1
x = x & (x -1 )

* 得到最低位的1
x & -x

* 清零 x&-x

[如何从十进制转换为二进制](https://zh.wikihow.com/%E4%BB%8E%E5%8D%81%E8%BF%9B%E5%88%B6%E8%BD%AC%E6%8D%A2%E4%B8%BA%E4%BA%8C%E8%BF%9B%E5%88%B6)

N queens 

```py
def totalNQueens(self, n): 
	if n < 1: return [] 
	self.count = 0 
	self.DFS(n, 0, 0, 0, 0) 
	return self.count
def DFS(self, n, row, cols, pie, na): 
	# recursion terminator 
	if row >= n: 
		self.count += 1 
		return
	bits = (~(cols | pie | na)) & ((1 << n) — 1)  # 得到当前所有的空位
	while bits: 
		p = bits & —bits # 取到最低位的1
		bits = bits & (bits — 1) # 表示在p位置上放入皇后
		self.DFS(n, row + 1, cols | p, (pie | p) << 1, (na | p) >> 1) 
        # 不需要revert  cols, pie, na 的状态
```

```C++
class Solution {
public:
    int totalNQueens(int n) {
        dfs(n, 0, 0, 0, 0);
        
        return this->res;
    }
    
    void dfs(int n, int row, int col, int ld, int rd) {
        if (row >= n) { res++; return; }
        
        // 将所有能放置 Q 的位置由 0 变成 1，以便进行后续的位遍历
        int bits = ~(col | ld | rd) & ((1 << n) - 1);
        while (bits > 0) {
            int pick = bits & -bits; // 注: x & -x
            dfs(n, row + 1, col | pick, (ld | pick) << 1, (rd | pick) >> 1);
            bits &= bits - 1; // 注: x & (x - 1)
        }
    }


private:
    int res = 0;
};
```

![alt test][image1]


## 布隆过滤器

一个长二进制向量，一系列随机散列函数。
查找是否可能存在（可能存在/不可能存在）


Pros ： 空间效率高，查询时间快

Cons ： 查全率高，查准率一般，需要进一步确认， 删除困难。

[布隆过滤器的原理和实现](https://www.cnblogs.com/cpselvis/p/6265825.html)

[使用布隆过滤器解决缓存击穿、垃圾邮件识别、集合判重](https://blog.csdn.net/tianyaleixiaowu/article/details/74721877)

[布隆过滤器 Python 实现示例](https://www.geeksforgeeks.org/bloom-filters-introduction-and-python-implementation/)

[高性能布隆过滤器 Python 实现示例](https://github.com/jhgg/pybloof)

```py
from bitarray import bitarray 
import mmh3 
class BloomFilter: 
	def __init__(self, size, hash_num): 
		self.size = size 
		self.hash_num = hash_num 
		self.bit_array = bitarray(size) 
		self.bit_array.setall(0) 
	def add(self, s): 
		for seed in range(self.hash_num): 
			result = mmh3.hash(s, seed) % self.size 
			self.bit_array[result] = 1 
	def lookup(self, s): 
		for seed in range(self.hash_num): 
			result = mmh3.hash(s, seed) % self.size 
			if self.bit_array[result] == 0: 
				return "Nope" 
		return "Probably" 
bf = BloomFilter(500000, 7) 
bf.add("dantezhao") 
print (bf.lookup("dantezhao")) 
print (bf.lookup("yyj")) 
```
```C++
#include <iostream>
#include <bitset>
#include <cmath>
 
using namespace std;

typedef unsigned int uint; 
const int DEFAULT_SIZE = 1 << 20;
const int seed[] = { 5, 7, 11, 13, 31, 37, 61 };


class BloomFilter {
public:
	BloomFilter() : hash_func_count(3) {}
    BloomFilter(int bitsize, int str_count) { 
    	hash_func_count = ceil((bitsize / str_count) * log(2));
	}
    ~BloomFilter() {}
	
	uint RSHash(const char *str, int seed);
	void Add(const char *str);
	bool LookUp(const char *str);
 
private:
	int hash_func_count;
	bitset<DEFAULT_SIZE> bits;
};

uint BloomFilter::RSHash(const char *str, int seed) {  
    uint base = 63689;
    uint hash = 0;    
     
    while (*str) {    
        hash = hash * base + (*str++);    
        base *= seed;    
    }    
     
    return (hash & 0x7FFFFFFF);    
}    
 
void BloomFilter::Add(const char* str) {
	int index = 0;
	for(int i = 0; i < hash_func_count; ++i) {
		index = static_cast<int>(RSHash(str, seed[i])) % DEFAULT_SIZE;
		bits[index] = 1;
	}
	
	return ;
}
 
bool BloomFilter::LookUp(const char* str) {
	int index = 0;
	for(int i = 0; i < hash_func_count; ++i) {
		index = static_cast<int>(RSHash(str, seed[i])) % DEFAULT_SIZE;
		if (!bits[index]) return false; 
	}
 
	return true;
}
```
## LRU Cache

Least Recently Used
Least Frequence Used
简单特征的推荐系统

[Understanding the Meltdown exploit](https://www.sqlpassion.at/archive/2018/01/06/understanding-the-meltdown-exploit-in-my-own-simple-words/)

[替换算法总揽](https://en.wikipedia.org/wiki/Cache_replacement_policies)

```py
class LRUCache(object): 

	def __init__(self, capacity): 
		self.dic = collections.OrderedDict() 
		self.remain = capacity

	def get(self, key): 
		if key not in self.dic: 
			return -1 
		v = self.dic.pop(key) 
		self.dic[key] = v   # key as the newest one 
		return v 

	def put(self, key, value): 
		if key in self.dic: 
			self.dic.pop(key) 
		else: 
			if self.remain > 0: 
				self.remain -= 1 
			else:   # self.dic is full
				self.dic.popitem(last=False) 
		self.dic[key] = value
```

```C++
struct CacheNode {
    int key, value;
    CacheNode *pre, *next;
      
    CacheNode(int key_ = 0, int value_ = 0) 
        : key(key_), value(value_), pre(NULL), next(NULL) {}
};

class LRUCache {
public:
    LRUCache(int capacity) 
        : _capacity(capacity), _head(new CacheNode()), _tail(_head) {}
    
    int get(int key) {
        auto it = _cache.find(key);
        if (it == _cache.end()) return -1;
        
        moveToTail(it->second);
        return it->second->value;
    }
    
    void put(int key, int value) {
        auto it = _cache.find(key);
        
        if (it != _cache.end()) {
            it->second->value = value;
            moveToTail(it->second);
        }
        else if ((int)_cache.size() < _capacity) {
            auto node = new CacheNode(key, value);
            addToTail(node);          
            _cache[key] = node;
        }
        else {
            // Reuse existing node
            _cache.erase(_head->next->key);
            moveToTail(_head->next);
            _tail->key = key; _tail->value = value;
            _cache[key] = _tail;
        }
    }
    
    ~LRUCache() {
        auto pCurr = _head;
        while (pCurr != NULL) {
            auto next = pCurr->next;
            delete pCurr;
            pCurr = next;
        }
    }
    
private:
    const int _capacity;
    CacheNode *const _head, *_tail;
    unordered_map<int, CacheNode*> _cache;
    
    void moveToTail(CacheNode *node) {
        if (node == _tail) return;
        
        node->pre->next = node->next;
        node->next->pre = node->pre;
        
        addToTail(node);
    }
    
    void addToTail(CacheNode *node) {
        node->next = _tail->next;
        _tail->next = node;
        node->pre = _tail;
        _tail = node;                   
    }
};
```

## 排序算法
 
 1. 比较类排序(非线性时间比较类排序)： 时间复杂度不能突破O(nlog n).

 2. 非比较类排序(线性时间非比较类排序)：只能适用于整形变量。

 [十大经典排序算法](https://www.cnblogs.com/onepixel/p/7674659.html)


快排

 ```C++
int random_partition(vector<int>& nums, int l, intr) {
  int random_pivot_index = rand() % (r - l +1) + l;  //随机选择pivot
  int pivot = nums[random_pivot_index];
  swap(nums[random_pivot_index], nums[r]);
  int i = l - 1;
  for (int j=l; j<r; j++) {
    if (nums[j] < pivot) {
      i++;
      swap(nums[i], nums[j]);
    }
  }
  int pivot_index = i + 1;
  swap(nums[pivot_index], nums[r]);
  return pivot_index;
}
void random_quicksort(vector<int>& nums, int l, int r) {
  if (l < r) {
    int pivot_index = random_partition(nums, l, r);
    random_quicksort(nums, l, pivot_index-1);
    random_quicksort(nums, pivot_index+1, r);
  }
}
 ```

 ```py
def quick_sort(begin, end, nums):
    if begin >= end:
        return
    pivot_index = partition(begin, end, nums)
    quick_sort(begin, pivot_index-1, nums)
    quick_sort(pivot_index+1, end, nums)
    
def partition(begin, end, nums):
    pivot = nums[begin]
    mark = begin
    for i in range(begin+1, end+1):
        if nums[i] < pivot:
            mark +=1
            nums[mark], nums[i] = nums[i], nums[mark]
    nums[begin], nums[mark] = nums[mark], nums[begin]
    return mark
 ```

归并

 ```C++
void mergeSort(vector<int> &nums, int left, int right) {
	if (left >= right) return;
	
	int mid = left + (right - left) / 2;
	mergeSort(nums, left, mid);
	mergeSort(nums, mid+1, right);
	
	merge(nums, left, mid, right);
}


void merge(vector<int> &nums, int left, int mid, int right) {
	vector<int> tmp(right-left+1);
	int i = left, j = mid+1, k = 0;
	
	while (i <= mid && j <= right) {
		tmp[k++] = nums[i] < nums[j] ? nums[i++] : nums[j++];
	}
	while (i <= mid) tmp[k++] = nums[i++];
	while (j <= right) tmp[k++] = nums[j++];
	
	for (i = left, k = 0; i <= right;) nums[i++] = tmp[k++];
}
 ```

```py
def mergesort(nums, left, right):
    if right <= left:
        return
    mid = (left+right) >> 1
    mergesort(nums, left, mid)
    mergesort(nums, mid+1, right)
    merge(nums, left, mid, right)

def merge(nums, left, mid, right):
    temp = []
    i = left
    j = mid+1
    while i <= mid and j <= right:
        if nums[i] <= nums[j]:
            temp.append(nums[i])
            i +=1
        else:
            temp.append(nums[j])
            j +=1
    while i<=mid:
        temp.append(nums[i])
        i +=1
    while j<=right:
        temp.append(nums[j])
        j +=1
    nums[left:right+1] = temp
```

Heap Sort

插入O(logN)，取最值O(1)

1. 数组依次建立小顶堆

2. 依次取堆顶元素，并删除

推荐堆直接调用系统的Heap或Priority Queue

```py
def heapify(parent_index, length, nums):
    temp = nums[parent_index]
    child_index = 2*parent_index+1
    while child_index < length:
        if child_index+1 < length and nums[child_index+1] > nums[child_index]:
            child_index = child_index+1
        if temp > nums[child_index]:
            break
        nums[parent_index] = nums[child_index]
        parent_index = child_index
        child_index = 2*parent_index + 1
    nums[parent_index] = temp


def heapsort(nums):
    for i in range((len(nums)-2)//2, -1, -1):
        heapify(i, len(nums), nums)
    for j in range(len(nums)-1, 0, -1):
        nums[j], nums[0] = nums[0], nums[j]
        heapify(0, j, nums)
```

```C++
void heapify(vector<int> &array, int length, int i) {
    int left = 2 * i + 1, right = 2 * i + 2;
    int largest = i;

    if (left < length && array[left] > array[largest]) {
        largest = left;
    }
    if (right < length && array[right] > array[largest]) {
        largest = right;
    }

    if (largest != i) {
        int temp = array[i]; array[i] = array[largest]; array[largest] = temp;
        heapify(array, length, largest);
    }


    return ;
}

void heapSort(vector<int> &array) {
    if (array.size() == 0) return ;

    int length = array.size();
    for (int i = length / 2 - 1; i >= 0; i--) 
        heapify(array, length, i);

    for (int i = length - 1; i >= 0; i--) {
        int temp = array[0]; array[0] = array[i]; array[i] = temp;
        heapify(array, i, 0);
    }

    return ;
}
```
[9 种经典排序算法可视化动画](https://www.bilibili.com/video/av25136272)

[6 分钟看完 15 种排序算法动画展示](https://www.bilibili.com/video/av63851336)

 实战 HW

位 1 的个数（Facebook、苹果在半年内面试中考过）
2 的幂（谷歌、亚马逊、苹果在半年内面试中考过）
颠倒二进制位（苹果在半年内面试中考过）
N 皇后（字节跳动、亚马逊、百度在半年内面试中考过）
N 皇后 II （亚马逊在半年内面试中考过）


（位运算DP）比特位计数（字节跳动、Facebook、MathWorks 在半年内面试中考过）

![alt test][image2]

数组的相对排序（谷歌在半年内面试中考过）
有效的字母异位词（Facebook、亚马逊、谷歌在半年内面试中考过）
力扣排行榜（Bloomberg 在半年内面试中考过）
合并区间（Facebook、字节跳动、亚马逊在半年内面试中常考）
翻转对（字节跳动在半年内面试中考过）

LRU 缓存机制（亚马逊、字节跳动、Facebook、微软在半年内面试中常考）

数组的相对排序（谷歌在半年内面试中考过）
有效的字母异位词（Facebook、亚马逊、谷歌在半年内面试中考过）
力扣排行榜（Bloomberg 在半年内面试中考过）
合并区间（Facebook、字节跳动、亚马逊在半年内面试中常考）
翻转对（字节跳动在半年内面试中考过）

[//]: # (Image References)

[image1]: ./pic/capture.png
[image2]: ./pic/capture1.png