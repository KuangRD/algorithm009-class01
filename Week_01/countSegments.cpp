class Solution {
public:
    int countSegments(string s) {
        int res = 0;
        istringstream words(s);
        string word;
        while (words >> word) res++;

        return res;
    }
};