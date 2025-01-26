class Solution {
public:
  void rotate(vector<int>& nums, int k) {
    vector<int> rotated_nums(nums.size());
    for (int i = 0; i < nums.size(); i++) {
      rotated_nums[(i + k) % nums.size()] = nums[i];
    }
    nums = rotated_nums;
  }
};
