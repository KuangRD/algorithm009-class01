class Solution {
 public:
  int numIslands(vector<vector<char>>& grid) {
    int res = 0;

    for (int row_idx = 0; row_idx < grid.size(); row_idx++)
      for (int col_idx = 0; col_idx < grid[0].size(); col_idx++)
        if (grid[row_idx][col_idx] == '1') {
          res++;
          bfs(grid, row_idx, col_idx);
        }
    return res;
  }

  void bfs(vector<vector<char>>& grid, int row_idx, int col_idx) {

    int d_coord[] = {0, 1, 0, -1, 0};
    queue<pair<int, int>> neighbour_queue;
    neighbour_queue.push(make_pair(row_idx, col_idx));

    while (!neighbour_queue.empty()) {
      pair<int, int> point = neighbour_queue.front();
      row_idx = point.first;
      col_idx = point.second;
      grid[row_idx][col_idx] = '0';
      neighbour_queue.pop();

      for (int i = 0; i < 4; i++) {
        int temp_row_idx = row_idx + d_coord[i], temp_col_idx = col_idx + d_coord[i+1];

        if (temp_row_idx < grid.size() && temp_col_idx < grid[0].size() &&
            temp_row_idx >= 0 && temp_col_idx >= 0) {
          if (grid[temp_row_idx][temp_col_idx] == '1') {
            grid[temp_row_idx][temp_col_idx] = '0';
            neighbour_queue.push({temp_row_idx, temp_col_idx});
          }
        }
      }
    }
  }
};
