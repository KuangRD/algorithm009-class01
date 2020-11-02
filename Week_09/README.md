学习笔记

[不可变字符串](https://lemire.me/blog/2017/07/07/are-your-strings-immutable/)

Atoi

```py
class Solution(object):
    def myAtoi(self, s):
        if len(s) == 0 : return 0
        ls = list(s.strip())
        
        sign = -1 if ls[0] == '-' else 1
        if ls[0] in ['-','+'] : del ls[0]
        ret, i = 0, 0
        while i < len(ls) and ls[i].isdigit() :
            ret = ret*10 + ord(ls[i]) - ord('0')
            i += 1
        return max(-2**31, min(sign * ret,2**31-1))
```

```C
int myAtoi(string str) {
   int res = 0;
   int sign = 1;
   size_t index = 0;
   if(str.find_first_not_of(' ') != string::npos) 
       index = str.find_first_not_of(' ');
   if(str[index] == '+' || str[index] == '-')
       sign = str[index] == '-' ? -1 : 1;
    
    while(index < str.size() && isdigit(str[index])) {
        res = res * 10 + (str[index++] - '0');
        if(res*sign > INT_MAX) return INT_MAX;
        if(res*sign < INT_MIN) return INT_MIN; 
    }

   return res*sign;
}
```

```C++
class Solution {
public:
    int myAtoi(string str) {
        auto i = getStartIndexOfNonSpace(str);
        if (i < 0) return 0;
        
        auto sign = handleSign(str, i);       
        auto num = sign * convertStringToLong(str, i);
        return convertLongToInt(num);
    }
    
private:
    int getStartIndexOfNonSpace(const string &str) {
        for (int i = 0; i < str.size(); ++i) {
            if (str[i] != ' ') return i;
        }
        
        return -1;
    }
    
    int handleSign(const string &str, int &i) {
        if (str[i] == '-') {
            ++i;
            return -1;
        }
        
        if (str[i] == '+') ++i;
        return 1;
    }
    
    long convertStringToLong(const string &str, int i) {
        long num = 0;        
        while(i < str.size()) {
            if (num > INT_MAX || !isdigit(str[i])) break;            
            num = num * 10 + str[i] - '0';
            ++i;
        }
        
        return num;
    }
    
    int convertLongToInt(const long &num) {
        if (num < INT_MIN) return INT_MIN;
        if (num > INT_MAX) return INT_MAX;     
        return (int)num;        
    }
};
```

[Boyer-Moore 算法](https://www.ruanyifeng.com/blog/2013/05/boyer-moore_string_search_algorithm.html)

[Sunday 算法](https://blog.csdn.net/u012505432/article/details/52210975)

[字符串匹配暴力法代码示例](https://shimo.im/docs/8G0aJqNL86wWrPUE)

[Rabin-Karp 代码示例](https://shimo.im/docs/1wnsM7eaZ6Ab9j9M)

[KMP 字符串匹配算法视频](https://www.bilibili.com/video/av11866460?from=search&seid=17425875345653862171)

[字符串匹配的 KMP 算法](http://www.ruanyifeng.com/blog/2013/05/Knuth%E2%80%93Morris%E2%80%93Pratt_algorithm.html)

最长子串、子序列问题
最长公共子序列（亚马逊、字节跳动、谷歌在半年内面试中考过）
编辑距离（亚马逊、字节跳动、谷歌在半年内面试中考过）
最长回文子串（亚马逊、华为、字节跳动在半年内面试常考）
字符串 +DP 问题
正则表达式匹配（Facebook、微软、字节跳动在半年内面试中考过）
题解： https://leetcode-cn.com/problems/regular-expression-matching/solution/ji-yu-guan-fang-ti-jie-gen-xiang-xi-de-jiang-jie-b/
通配符匹配（Facebook、微软、字节跳动在半年内面试中考过）
不同的子序列（MathWorks 在半年内面试中考过）