class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int res = 0;
        
        for (int row = 0; row < grid.size(); row++) {
            for (int col = 0; col < grid[0].size(); col++) {
                if (grid[row][col] == '1') {
                    res++;
                    bfs(grid, row, col);
                }
            }
        }

        return res;
    }
private:
    // set<int, int>  visted;
    void bfs(vector<vector<char>>& grid, int row, int col) {
        int offsets[] = {0, 1, 0, -1, 0};
        queue<pair<int, int>> neibours;
        neibours.push({row, col});
        while (!neibours.empty()) {
            pair<int, int> neibour = neibours.front();
            row = neibour.first;
            col = neibour.second;
            grid[row][col] = '0';
            neibours.pop();
            for (int i = 0; i < 4; i++) {
                if (row + offsets[i] >= 0 && row + offsets[i] < grid.size() && 
                    col + offsets[i+1] >= 0 && col + offsets[i+1] < grid[0].size())
                    if (grid[row + offsets[i]][col + offsets[i+1]] == '1') {
                        grid[row + offsets[i]][col + offsets[i+1]] = '0';
                        neibours.push({row + offsets[i], col + offsets[i+1]});
                    }
            }
        }
    }
};