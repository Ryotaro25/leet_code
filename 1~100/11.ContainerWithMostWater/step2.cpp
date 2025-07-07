class Solution {
public:
  int maxArea(vector<int>& heights) {
    int left = 0;
    int right = heights.size() - 1;
    int max_amount = 0;
    while (left < right) {
      int width = right - left;
      int height = min(heights[left], heights[right]);
      max_amount = max(max_amount, height * width);
      if (heights[left] <= heights[right]) {
        left++;
      } else {
        right--;
      }
    }
    return max_amount;
  }
};
