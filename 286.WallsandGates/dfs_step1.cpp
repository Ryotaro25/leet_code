class Solution {
  // dfsだとTLE
  public:
    void wallsAndGates(vector<vector<int>>& rooms) {
      for (int row = 0; row < rooms.size(); row++) {
        for (int col = 0; col < rooms[0].size(); col++) {
          if (rooms[row][col] == GATE) {
            FillDistanceFromGate(rooms, row, col, 0);
          }
        }
      }
    }

  private:
    static constexpr int OBSTACLE = -1;
    static constexpr int GATE = 0;
    static constexpr int EMPTY = 2147483647;

    void FillDistanceFromGate(vector<vector<int>>& rooms, int row, int col, int distance) {
      if (row < 0 || row >= rooms.size() || col < 0 || col >= rooms[0].size()) {
        return;
      }
      if (rooms[row][col] < distance) {
        return;
      }
      rooms[row][col] = distance;
      int next_distance = distance + 1;
      FillDistanceFromGate(rooms, row - 1, col, next_distance);
      FillDistanceFromGate(rooms, row + 1, col, next_distance);
      FillDistanceFromGate(rooms, row, col + 1, next_distance);
      FillDistanceFromGate(rooms, row, col - 1, next_distance);
    }
  };
