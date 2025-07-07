class Solution {
public:
  void setZeroes(vector<vector<int>>& matrix) {
    // 1列目を全て0で初期化する
    // 「行0に0があった」のか「列0に0があった」のか判別するため
    bool has_zero_in_first_col = false;
    for (int row = 0; row < matrix.size(); row++) {
      if (matrix[row][0] == 0) {
        has_zero_in_first_col = true;
      }
      for (int col = 1; col < matrix[0].size(); col++) {
        if (matrix[row][col] == 0) {
          matrix[row][0] = 0;
          matrix[0][col] = 0;
        }
      }
    }

    for (int row = 1; row < matrix.size(); row++) {
      for (int col = 1; col < matrix[0].size(); col++) {
        if (matrix[row][0] == 0 || matrix[0][col] == 0) {
          matrix[row][col] = 0;
        }
      }
    }

    if (matrix[0][0] == 0) {
      for (int col = 0; col < matrix[0].size(); col++) {
        matrix[0][col] = 0;
      }
    }
    if (has_zero_in_first_col) {
      for (int row = 0; row < matrix.size(); row++) {
        matrix[row][0] = 0;
      }
    }
  }
};
