class Solution {
public:
    vector<string> generateParenthesis(int n) {
        generateParenthesis_dfs(0, 0, n,"");
        return res;
    }
private:
    vector<string> res;
    void generateParenthesis_dfs(int left, int right, int n,string s) {
        if (left == n && right == n) {
            res.push_back(s);
            return;        
        }

        if (left < n) generateParenthesis_dfs(left+1, right, n, s+'(');
        if (right < n && left > right) generateParenthesis_dfs(left, right+1, n, s+')');
    }
};