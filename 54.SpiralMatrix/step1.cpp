class Solution {
public:
  vector<int> spiralOrder(vector<vector<int>>& matrix) {
    int r = 0;
    int row_size = matrix.size();
    int c = 0;
    int col_size = matrix[0].size();

    vector<int> spiral_ordered;

    while (r < row_size && c < col_size) {
      // 右に進む
      for (int i = c; i < col_size; i++) {
        spiral_ordered.push_back(matrix[r][i]);
      }
      r++;

      // 下に進む
      for (int i = r; i < row_size; i++) {
        spiral_ordered.push_back(matrix[i][col_size - 1]);
      }
      col_size--;

      // 左に進む（必要であれば）
      if (r < row_size) {
        for (int i = col_size - 1; i >= c; i--) {
          spiral_ordered.push_back(matrix[row_size - 1][i]);
        }
        row_size--;
      }

      // 上に進む（必要であれば）
      if (c < col_size) {
        for (int i = row_size - 1; i >= r; i--) {
          spiral_ordered.push_back(matrix[i][c]);
        }
        c++;
      }
    }

    return spiral_ordered;
  }
};
