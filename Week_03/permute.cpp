class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> output;
        dfs(res, nums, 0);
        return res;
    }

    void dfs(vector<vector<int>> &res, vector<int> &output, int idx) {
        if (idx == output.size()) {
            res.emplace_back(output);
            return;
        }

        for (int i=idx; i<output.size(); i++) {
            swap(output[i], output[idx]);
            dfs(res, output, idx+1);
            swap(output[idx], output[i]);
        }
        // return res;
    }
};