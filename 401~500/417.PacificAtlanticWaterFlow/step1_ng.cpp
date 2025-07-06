class Solution {
public:
  vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
    if (heights.empty()) {
      return {};
    }
    int row_size = heights.size();
    int col_size = heights[0].size();

    vector<vector<int>> results;
    for (int row = 0; row < row_size; row++) {
      for (int col = 0; col < col_size; col++) {
        vector<bool> is_reachable(2, false);
        TraverseIsland(heights, row, col, is_reachable);
        if (is_reachable[0] && is_reachable[1]) {
          results.push_back({row, col});
        }
      }
    }

    return results;
  }

private:
  void TraverseIsland(const vector<vector<int>>& heights, int row, int col, vector<bool>& is_reachable) {
    if (row == 0 || col == 0) {
      is_reachable[0] = true;
    }
    if (row == heights.size() - 1 || col == heights[0].size() - 1) {
      is_reachable[1] = true;
    }

    if (row - 1 >= 0 && heights[row][col] >= heights[row - 1][col]) {
      TraverseIsland(heights, row - 1, col, is_reachable);
    }
    if (col + 1 < heights[0].size() && heights[row][col] >= heights[row][col + 1]) {
      TraverseIsland(heights, row, col + 1, is_reachable);
    }
    if (row + 1 < heights.size() && heights[row][col] >= heights[row +  1][col]) {
      TraverseIsland(heights, row + 1, col, is_reachable);
    }
    if (col - 1 >= 0 && heights[row][col] >= heights[row][col - 1]) {
      TraverseIsland(heights, row, col - 1, is_reachable);
    }
  }
};
