class Solution {
public:
  vector<vector<int>> pacificAtlantic(vector<vector<int>>& grid) {
    if (grid.empty() || grid[0].empty()) {
      return {};
    }
    int height = grid.size();
    int width = grid[0].size();

    vector<vector<bool>> is_reachable_to_pacific(height, vector<bool>(width, false));
    vector<vector<bool>> is_reachable_to_atlantic(height, vector<bool>(width, false));

    for (int row = 0; row < height; row++) {
      TraverseIsland(grid, row, 0, is_reachable_to_pacific);
      TraverseIsland(grid, row, width - 1, is_reachable_to_atlantic);
    }

    for (int col = 0; col < width; col++) {
      TraverseIsland(grid, 0, col, is_reachable_to_pacific);
      TraverseIsland(grid, height - 1, col, is_reachable_to_atlantic);
    }

    vector<vector<int>> flowable_islands;
    for (int row = 0; row < height; row++) {
      for (int col = 0; col < width; col++) {
        if (is_reachable_to_pacific[row][col] && is_reachable_to_atlantic[row][col]) {
          flowable_islands.push_back({row, col});
        }
      }
    }
    return flowable_islands;
  }

private:
  void TraverseIsland(vector<vector<int>>& grid, int row, int col, vector<vector<bool>>& is_reachable) {
    is_reachable[row][col] = true;
    vector<pair<int, int>> directions = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

    for (auto direction : directions) {
      int next_row = row + direction.first;
      int next_col = col + direction.second;

      if (next_row < 0 || next_row >= grid.size() || next_col < 0 || next_col >= grid[0].size()) {
        continue;
      }
      if (is_reachable[next_row][next_col]) {
        continue;
      }
      if (grid[next_row][next_col] < grid[row][col]) {
        continue;
      }
      TraverseIsland(grid, next_row, next_col, is_reachable);
    }
  }
};
