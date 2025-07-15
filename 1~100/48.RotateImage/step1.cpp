class Solution {
public:
  void rotate(vector<vector<int>>& matrix) {
    if (matrix.empty() || matrix[0].empty()) {
      return;
    }
    int top = 0;
    int bottom = matrix.size() - 1;

    while (top < bottom) {
      for (int col = 0; col < matrix[0].size(); col++) {
        swap(matrix[top][col], matrix[bottom][col]);
      }
      top++;
      bottom--;
    }


    for (int row = 0; row < matrix.size(); row++) {
      // the matrix would be back to its original state
      // without have the row + 1 condition
      for (int col = row + 1; col < matrix[0].size(); col++) {
        swap(matrix[row][col], matrix[col][row]);
      }
    }
  }
};
