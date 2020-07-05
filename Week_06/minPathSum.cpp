const int INF = 1 << 20;
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if (grid.size() < 1 || grid[0].size() < 1) return -1;
        // vector<vector<int>> dp_matrix(grid);
        int dp_matrix[grid.size()][grid[0].size()];

        dp_matrix[0][0] = grid[0][0];
        for (int i = 1; i < grid.size(); i++) dp_matrix[i][0] = dp_matrix[i-1][0]+grid[i][0];
        for (int j = 1; j < grid[0].size(); j++) dp_matrix[0][j] = dp_matrix[0][j-1]+grid[0][j];     

        for (int i = 1; i < grid.size(); i++) {
            for (int j = 1; j < grid[0].size(); j++) {
                dp_matrix[i][j] = grid[i][j] + min(dp_matrix[i-1][j], dp_matrix[i][j-1]); 
            }
        }
        return dp_matrix[grid.size()-1][grid[0].size()-1];
    }
};