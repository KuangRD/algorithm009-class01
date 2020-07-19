class Solution {
public:
    string longestPalindrome(string s) {
        // Dumm Version
        int idx_start = 0;
        int current_max = 0;
        // int l_idx = 0, r_idx = 0;
        if(s.size()==0)
            return "";

        for (int i = 0 ; i < s.size(); i++){
            int dummy_l_idx, dummy_r_idx;
            if (s[i] == s[i+1]){
                 dummy_l_idx = i;
                 dummy_r_idx = i+1;
                 PalindromeRecursiveCheck(s, dummy_l_idx, dummy_r_idx);

                if (dummy_r_idx - dummy_l_idx + 1 > current_max) {
                    current_max = dummy_r_idx - dummy_l_idx + 1;
                    idx_start = dummy_l_idx;
                }
            }

             dummy_l_idx = i;
             dummy_r_idx = i;
             PalindromeRecursiveCheck(s, dummy_l_idx, dummy_r_idx);

            if (dummy_r_idx - dummy_l_idx + 1 > current_max){
                current_max = dummy_r_idx - dummy_l_idx + 1;
                idx_start = dummy_l_idx;
            }
        }

        return s.substr(idx_start, current_max);
    }

    int PalindromeRecursiveCheck(string s, int &i, int &j){
        while (i != 0 and j != s.size()-1 and (s[i-1] == s[j+1])){
            i = i-1;
            j = j+1;
        }
        return 0;
    }
};