class Solution {
public:
  int maxAreaOfIsland(vector<vector<int>>& grid) {
    if (grid.empty() || grid[0].empty()) {
      return 0;
    }
    int max_area_island = 0;
    for (int row = 0; row < grid.size(); row++) {
      for (int col = 0; col < grid[0].size(); col++) {
        if (grid[row][col] == WATER || grid[row][col] == VISITED) {
          continue;
        }
        int area_island = 0;
        CountLand(grid, row, col, area_island);
        max_area_island = max(max_area_island, area_island);
      }
    }
    return max_area_island;
  }

private:
  static constexpr int LAND = 1;
  static constexpr int WATER = 0;
  static constexpr int VISITED = -1;

  void CountLand(vector<vector<int>>& grid, int row, int col, int& area_island) {
    if (row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size()) {
      return;
    }
    if (grid[row][col] == WATER || grid[row][col] == VISITED) {
      return;
    }
    area_island++;
    grid[row][col] = VISITED;

    vector<vector<int>> directions = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    for (auto direction : directions) {
      int next_row = row + direction[0];
      int next_col = col + direction[1];
      CountLand(grid, next_row, next_col, area_island);
    }
  }
};
