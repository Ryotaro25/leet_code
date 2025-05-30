// TLE because the order is O(n^2)
class Solution {
public:
  int findMaxLength(vector<int>& nums) {
    if (nums.empty()) {
      return 0;
    }
    vector<int> cumulative_sums(nums.size() + 1, 0);
    for (int i = 0; i < nums.size(); i++) {
      int val = nums[i] == 1 ? 1 : -1;
      cumulative_sums[i + 1] = cumulative_sums[i] + val;
    }

    int max_length = 0;
    for (int left = 0; left < cumulative_sums.size(); left++) {
      for (int right = left + 1; right < cumulative_sums.size(); right++) {
        if (cumulative_sums[left] == cumulative_sums[right]) {
          max_length = max(max_length, right - left);
        }
        
      }
    }
    return max_length;
  }
};
