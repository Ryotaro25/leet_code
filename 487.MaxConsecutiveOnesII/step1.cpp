// bruteforce
class Solution {
public:
  int findMaxConsecutiveOnes(vector<int>& nums) {

    int max_consecutive_ones = 0;
    for (int i = 0; i < nums.size(); i++) {
      int cnt = 0;
      int num_zeros = 0;
      for (int j = i; j < nums.size(); j++) {
        if (nums[j] == 0) {
          num_zeros++;
        }
        if (num_zeros < 2) {
          cnt++;
        }
      }
      max_consecutive_ones = max(max_consecutive_ones, cnt);
    }
      
    return max_consecutive_ones;
  }
};
