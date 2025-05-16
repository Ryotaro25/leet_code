class Solution {
public:
  vector<int> findDiagonalOrder(vector<vector<int>>& mat) {

    map<int, vector<int>> sumed_index_to_val;
    for (int i = 0; i < mat.size(); i++) {
      for (int j = 0; j < mat[i].size(); j++) {
        sumed_index_to_val[i + j].push_back(mat[i][j]);
      }
    }


    vector<int> diagonal_ordered;
    for (auto [index, vals] : sumed_index_to_val) {
      if (index % 2 == 0) {
        for (int i = vals.size() - 1; i >= 0; i--) {
          diagonal_ordered.push_back(vals[i]);
        }
      } else {
        for (int i = 0; i < vals.size(); i++) {
          diagonal_ordered.push_back(vals[i]);
        }
      }
    }

    return diagonal_ordered;
  }
};
