// https://leetcode.com/problems/trapping-rain-water/
class Solution {
public:
    int trap(vector<int>& height) {
        int res = 0;
        stack<int> valley_idx;
        // bool in_valley = false;
        for (int i = 0; i < height.size(); i++) {
            while (!valley_idx.empty() && height[i] > height[valley_idx.top()]) {
                int top = valley_idx.top();
                valley_idx.pop();
                if (valley_idx.empty()) break;
                int distance = i - valley_idx.top() -1;
                int effective_height = min(height[i], height[valley_idx.top()]) - height[top];
                res += distance * effective_height;
            }
            valley_idx.push(i);
        }
        return res;
    }
};