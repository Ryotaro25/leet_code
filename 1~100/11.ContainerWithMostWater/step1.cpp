class Solution {
public:
  int maxArea(vector<int>& heights) {
    int max_amount = 0;
    for (int i = 0; i < heights.size(); i++) {
      for (int j = i + 1; j < heights.size(); j++) {
        int height = min(heights[i], heights[j]);
        int width = j - i;

        max_amount = max(max_amount, height * width);
      }
    }
    return max_amount;
  }
};
