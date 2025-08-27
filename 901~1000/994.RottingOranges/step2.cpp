class Solution {
public:
  int orangesRotting(vector<vector<int>>& grid) {
    if (grid.empty() || grid[0].empty()) {
      return 0;
    }

    int num_fresh_orange = 0;
    queue<PositionAndMinutes> position_and_minitues;
    for (int row = 0; row < grid.size(); row++) {
      for (int col = 0; col < grid[0].size(); col++) {
        if (grid[row][col] == FRESH) {
          num_fresh_orange++;
          continue;
        }
        if (grid[row][col] == ROTTEN) {
          position_and_minitues.push({row, col, 0});
        }
      }
    }

    int min_num_minutes = 0;
    while (!position_and_minitues.empty()) {
      auto [row, col, num_minutes] = position_and_minitues.front();
      position_and_minitues.pop();

      min_num_minutes = max(min_num_minutes, num_minutes);
      vector<int> row_directions = {-1, 0, 1, 0};
      vector<int> col_directions = {0, 1, 0, -1};
      for (int i = 0; i < 4; i++) {
        int next_row = row + row_directions[i];
        int next_col = col + col_directions[i];
        if (!IsValidPosition(grid, next_row, next_col)) {
          continue;
        }
        if (grid[next_row][next_col] == EMPTY || grid[next_row][next_col] == ROTTEN) {
          continue;
        }
        grid[next_row][next_col] = ROTTEN;
        num_fresh_orange--;
        position_and_minitues.push({next_row, next_col, num_minutes + 1});
      }
    }

    if (num_fresh_orange != 0) {
      return -1;
    }
    return min_num_minutes;
  }

private:
  struct PositionAndMinutes {
    int row;
    int col;
    int num_minutes;
  };

  static constexpr int EMPTY = 0;
  static constexpr int FRESH = 1;
  static constexpr int ROTTEN = 2;

  bool IsValidPosition(vector<vector<int>>& grid, int row, int col) {
    if (row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size()) {
      return false;
    }
    return true;
  }
};
