class Solution {
public:
  vector<vector<int>> generate(int numRows) {
    vector<vector<int>> pascals_triangle;
    pascals_triangle.push_back({1});

    for (int i = 1; i < numRows; i++) {
      vector<int> row;
      // 左端
      row.push_back(1);

      vector<int> previous_row = pascals_triangle[i - 1];
      for (int j = 1; j < i; j++) {
        row.push_back(previous_row[j - 1] + previous_row[j]);
      }

      // 右端
      row.push_back(1);
      pascals_triangle.push_back(row);
    }
    return pascals_triangle;
  }
};
