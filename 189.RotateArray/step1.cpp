class Solution {
public:
  void rotate(vector<int>& nums, int k) {
    vector<int> rotated_nums(nums.size());
    for (int i = 0; i < nums.size(); i++) {
      int target_index = i + k;
      if (target_index > nums.size() - 1) {
        target_index %= nums.size();
      }
      rotated_nums[target_index] = nums[i];
    }
    nums = rotated_nums;
  }
};
