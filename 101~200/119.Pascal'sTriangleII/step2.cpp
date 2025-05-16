// no need to stroe every rows in vector<vector<int>>
class Solution {
public:
  vector<int> getRow(int rowIndex) {
    vector<int> target_row = {1};
    for (int i = 1; i <= rowIndex; i++) {
      vector<int> row;
      row.push_back(1);
      for (int j = 1; j < i; j++) {
        row.push_back(target_row[j - 1] + target_row[j]);
      }
      row.push_back(1);
      target_row = row;
    }

    return target_row;
  }
};
