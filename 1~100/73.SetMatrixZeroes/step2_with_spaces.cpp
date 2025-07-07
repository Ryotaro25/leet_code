class Solution {
public:
  void setZeroes(vector<vector<int>>& matrix) {
    if (matrix.empty()) {
      return;
    }
    set<int> target_rows;
    set<int> target_cols;
    for (int row = 0; row < matrix.size(); row++) {
      for (int col = 0; col < matrix[0].size(); col++) {
        if (matrix[row][col] == 0) {
          target_rows.insert(row);
          target_cols.insert(col);
        }
      } 
    }

    for (int row = 0; row < matrix.size(); row++) {
      for (int col = 0; col < matrix[0].size(); col++) {
        if (target_rows.contains(row) || target_cols.contains(col)) {
          matrix[row][col] = 0;
        }
      } 
    }
  }
};
