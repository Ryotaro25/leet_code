class Solution {
public:
  void setZeroes(vector<vector<int>>& matrix) {
    if (matrix.empty()) {
      return;
    }
    vector<vector<int>> visited(matrix.size(), vector<int>(matrix[0].size(), -1));
    for (int i = 0; i < matrix.size(); i++) {
      for (int j = 0; j < matrix[0].size(); j++) {
        if (matrix[i][j] == 0 && visited[i][j] == -1) {
          SetZero(matrix, visited, i - 1, j, 1);
          SetZero(matrix, visited, i, j + 1, 2);
          SetZero(matrix, visited, i + 1, j, 3);
          SetZero(matrix, visited, i, j - 1, 4);
        }
      }
    }
  }
  void SetZero(vector<vector<int>>& matrix, vector<vector<int>>& visited, int i, int j, int dir) {
    while (0 <= i && i < matrix.size() && 0 <= j && j < matrix[0].size()) {
      matrix[i][j] = 0;
      visited[i][j] = 1;

      if (dir == 1) {
        i--;
      } else if (dir == 2) {
        j++;
      } else if (dir == 3) {
        i++;
      } else if (dir == 4) {
        j--;
      }
    }
  }
};
