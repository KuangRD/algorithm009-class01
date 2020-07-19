class Solution {
public:
    string reverseStr(string s, int k) {
        int idx = 0;
        while (idx < s.size()) {
            int right = min(int(s.size()), idx + k);
            reverse(s.begin() + idx, s.begin() + right);
            idx += 2*k;
        }
        return s;
    }
};