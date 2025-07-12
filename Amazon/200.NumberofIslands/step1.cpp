class Solution {
public:
  int numIslands(vector<vector<char>>& grid) {
    int num_island = 0;
    for (int row = 0; row < grid.size(); row++) {
      for (int col = 0; col < grid[0].size(); col++) {
        if (grid[row][col] == WATER) {
          continue;
        }
        if (grid[row][col] == VISITED) {
          continue;
        } 
        num_island++;
        TraverseIsland(grid, row, col);
      }
    }
    return num_island;
  }

private:
  static constexpr char VISITED = '2';
  static constexpr char WATER = '0';
  static constexpr char LAND = '1';

  void TraverseIsland(vector<vector<char>>& grid, int row, int col) {
    if (row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size()) {
      return;
    }
    if (grid[row][col] == WATER) {
      return;
    }
    if (grid[row][col] == VISITED) {
      return;
    }
    grid[row][col] = VISITED;
    vector<vector<int>> directions = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    for (auto direction : directions) {
      int next_row = row + direction[0];
      int next_col = col + direction[1];

      TraverseIsland(grid, next_row, next_col);
    }
  }
};
