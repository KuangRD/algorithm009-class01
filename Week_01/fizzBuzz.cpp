class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> res; 
        map<int, string> mDict;
        mDict[3] = "Fizz";
        mDict[5] = "Buzz";

        for (int i = 1; i <= n; i++) {
            string dum_str = "";
            for (auto elem : mDict) {
                if (i % elem.first == 0) dum_str += elem.second;
            }
            if (dum_str == "") dum_str += to_string(i);
            res.push_back(dum_str);
        } 
        return res;
    }
};