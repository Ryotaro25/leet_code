class Solution {
public:
  vector<vector<int>> pacificAtlantic(vector<vector<int>>& grid) {
    if (grid.empty() || grid[0].empty()) {
      return {};
    }

    int height = grid.size();
    int width = grid[0].size();
    vector<vector<bool>> are_reachable_to_pacific(height, vector<bool>(width, false));
    vector<vector<bool>> are_reachable_to_atlantic(height, vector<bool>(width, false));

    for (int row = 0; row < height; row++) {
      TraverseIsland(grid, row, 0, are_reachable_to_pacific);
      TraverseIsland(grid, row, width - 1, are_reachable_to_atlantic);
    }
    for (int col = 0; col < width; col++) {
      TraverseIsland(grid, 0, col, are_reachable_to_pacific);
      TraverseIsland(grid, height - 1, col, are_reachable_to_atlantic);
    }

    vector<vector<int>> results;
    for (int row = 0; row < height; row++) {
      for (int col = 0; col < width; col++) {
        if (are_reachable_to_pacific[row][col] && are_reachable_to_atlantic[row][col]) {
          results.push_back({row, col});
        }
      }
    }
    return results;
  }

private:
  void TraverseIsland(const vector<vector<int>>& grid, int row, int col, vector<vector<bool>>& reachable) {
    reachable[row][col] = true;

    vector<pair<int, int>> directions = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    for (auto direction : directions) {
      int next_row = row + direction.first;
      int next_col = col + direction.second;

      if (next_row < 0 || next_row >= grid.size() || next_col < 0 || next_col >= grid[0].size()) {
        continue;
      }
      if (reachable[next_row][next_col]) {
        continue;
      }
      if (grid[next_row][next_col] < grid[row][col]) {
        continue;
      }
      TraverseIsland(grid, next_row, next_col, reachable);
    }
  }
};
