class Solution {
public:
  void rotate(vector<int>& nums, int k) {
    int steps = k % nums.size();
    int last_index = nums.size() - 1;
    reverse(nums, 0, last_index);
    reverse(nums, 0, steps - 1);
    reverse(nums, steps, last_index);
  }

  void reverse(vector<int>& nums, int left, int right) {
    while (left < right) {
      swap(nums[left], nums[right]);
      left++;
      right--;
    }
  }
};
