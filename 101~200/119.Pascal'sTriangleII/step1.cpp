class Solution {
public:
  vector<int> getRow(int rowIndex) {
    vector<vector<int>> pascals_triangle;
    pascals_triangle.push_back({1});

    for (int i = 1; i <= rowIndex; i++) {
      vector<int> row;
      row.push_back(1);

      vector<int> previous = pascals_triangle[i - 1];
      for (int j = 1; j < i; j++) {
        row.push_back(previous[j - 1] + previous[j]);
      }
      row.push_back(1);
      pascals_triangle.push_back(row);
    }

    return pascals_triangle[rowIndex];
  }
};
