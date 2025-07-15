class Solution {
public:
  vector<int> spiralOrder(vector<vector<int>>& matrix) {
    if (matrix.empty() || matrix[0].empty()) {
      return {};
    }
    
    vector<int> spiral_ordered;
    int row_start =  0;
    int row_end = matrix.size();
    int col_start = 0;
    int col_end = matrix[0].size();

    while (row_start < row_end && col_start < col_end) {
      for (int col = col_start; col < col_end; col++) {
        spiral_ordered.push_back(matrix[row_start][col]);
      }
      row_start++;

      for (int row = row_start; row < row_end; row++) {
        spiral_ordered.push_back(matrix[row][col_end - 1]);
      }
      col_end--;

      if (row_start != row_end) {
        for (int col = col_end - 1; col >= col_start; col--) {
          spiral_ordered.push_back(matrix[row_end - 1][col]);
        }
        row_end--;
      }
      

      if (col_start != col_end) {
        for (int row = row_end - 1; row >= row_start; row--) {
        spiral_ordered.push_back(matrix[row][col_start]);
        }
        col_start++;
      }
      
    }

    return spiral_ordered;
  }
};
