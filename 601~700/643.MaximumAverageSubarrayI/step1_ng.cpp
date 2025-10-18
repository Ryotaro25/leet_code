class Solution {
public:
  double findMaxAverage(vector<int>& nums, int k) {
    int left = 0;
    int right = 0;
    double sum = 0.0;
    double max_average = numeric_limits<double>::min();
    while (left < nums.size() && right < nums.size()) {
      if (right - left + 1 < k) {
        sum += static_cast<double>(nums[right]);
        right++;
      } else {
        sum -= static_cast<double>(nums[left]);
        left++;
      }
      if (right - left + 1 == k) {
        cout << "left: " << left << ", right: " << right << ", sum: " << sum << ", avg: "<< sum / k << endl;
        max_average = max(max_average, sum / k);
      }
    }
    return max_average;
  }
};
