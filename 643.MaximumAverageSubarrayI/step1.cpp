class Solution {
public:
  double findMaxAverage(vector<int>& nums, int k) {
    if (nums.empty()) {
      return 0.0;
    }

    int left = 0;
    int right = 0;
    double sum = 0.0;
    // minだと動かない
    double max_average = numeric_limits<double>::lowest();
    while (right < nums.size()) {
      sum += static_cast<double>(nums[right]);
      if (right - left + 1 >= k) {
        max_average = max(max_average, sum / k);
        sum -= static_cast<double>(nums[left]);
        left++;
      }
      right++;
    }
    return max_average;
  }
};
