class Solution {
public:
  int longestConsecutive(vector<int>& nums) {
    if (nums.empty()) {
      return 0;
    }
    int longest_length = 1;
    for (int i = 0; i < nums.size(); i++) {
      int current_num = nums[i];
      int current_length = 1;
      while (HasNum(nums, current_num + 1)) {
        current_length++;
        current_num++;
      }
      longest_length = max(longest_length, current_length);
    }
    return longest_length;
  }

private:
  int HasNum(const vector<int>& nums, int target) {
    for (int num : nums) {
      if (target == num) {
        return true;
      }
    }
    return false;
  }
};