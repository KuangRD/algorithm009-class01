class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> char_idx_dict; // char & index+1
        for (int i = 0; i < s.size(); i++) {
            if (char_idx_dict.find(s[i]) != char_idx_dict.end()) char_idx_dict[s[i]] += s.size()+1;
            else char_idx_dict[s[i]] = i;
        }

        int idx = s.size();
        for (auto& x: char_idx_dict) idx = min(x.second, idx); 
        
        return idx == s.size() ? -1 :idx;
    }
};