class Solution {
public:
  vector<vector<int>> pacificAtlantic(vector<vector<int>>& grid) {
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
    if (is_reachable[row][col]) {
      return;
    }
    is_reachable[row][col] = true;

    int current_height = grid[row][col];
    if (row - 1 >= 0 && grid[row - 1][col] >= current_height) {
      TraverseIsland(grid, row - 1, col, is_reachable);
    }
    if (col + 1 < grid[0].size() && grid[row][col + 1] >= current_height) {
      TraverseIsland(grid, row, col + 1, is_reachable);
    }
    if (row + 1 < grid.size() && grid[row + 1][col] >= current_height) {
      TraverseIsland(grid, row + 1, col, is_reachable);
    }
    if (col - 1 >= 0 && grid[row][col - 1] >= current_height) {
      TraverseIsland(grid, row, col - 1, is_reachable);
    }
  }
};
