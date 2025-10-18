class Solution {
public:
  double findMaxAverage(vector<int>& nums, int k) {
    double sum = 0.0;
    for (int i = 0; i < k; i++) {
      sum += nums[i];
    }

    double max_average = sum / k;
    for (int i = k; i < nums.size(); i++) {
      sum += nums[i] - nums[i - k];
      max_average = max(max_average, sum / k);
    }
    return max_average;
  }
};
