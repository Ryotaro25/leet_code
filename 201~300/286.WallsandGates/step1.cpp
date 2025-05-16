class Solution {
  public:
    void wallsAndGates(vector<vector<int>>& rooms) {
      queue<RowAndCol> empty_positions;
      for (int row = 0; row < rooms.size(); row++) {
        for (int col = 0; col < rooms[0].size(); col++) {
          if (rooms[row][col] == GATE) {
            empty_positions.push({row, col});
          }
        }
      }

      while (!empty_positions.empty()) {
        auto [row, col] = empty_positions.front();
        empty_positions.pop();

        for (auto direction : directions) {
          int new_row = row + direction[0];
          int new_col = col + direction[1];

          if (new_row < 0 || new_row >= rooms.size() || new_col < 0 || new_col >= rooms[0].size()) {
            continue;
          }
          if (rooms[new_row][new_col] != EMPTY) {
            continue;
          }
          rooms[new_row][new_col] = rooms[row][col] + 1;
          empty_positions.push({new_row, new_col});
        }
      }
    }
  
  private:
    static constexpr int OBSTACLE = -1;
    static constexpr int GATE = 0;
    static constexpr int EMPTY = 2147483647;

    vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

    struct RowAndCol {
      int row;
      int col;
    };
  };
