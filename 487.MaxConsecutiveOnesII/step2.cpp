// sliding window
class Solution {
public:
  int findMaxConsecutiveOnes(vector<int>& nums) {
    int right = 0;
    int left = 0;
    int max_consecutive_ones = 0;
    int num_zeros = 0;

    while (right < nums.size()) {
      if (nums[right] == 0) {
        num_zeros++;
      }

      while (num_zeros == 2) {
        if (nums[left] == 0) {
          num_zeros--;
        }
        left++;
      }
      
      max_consecutive_ones = max(max_consecutive_ones, right - left + 1);
      right++;
    }

    return max_consecutive_ones;
  }
};
