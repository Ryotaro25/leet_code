class Solution {
public:
  int heightChecker(vector<int>& heights) {
    vector<int> ordered_heights = heights;
    sort(ordered_heights.begin(), ordered_heights.end());

    int cnt = 0;
    for (int i = 0; i < heights.size(); i++) {
      if (heights[i] != ordered_heights[i]) {
        cnt++;
      }
    }

    return cnt;
  }
};
