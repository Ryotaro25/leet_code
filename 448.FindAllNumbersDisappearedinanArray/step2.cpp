// in place
class Solution {
public:
  vector<int> findDisappearedNumbers(vector<int>& nums) {
    for (int i = 0; i < nums.size(); i++) {
      int target_index = abs(nums[i]) - 1;

      if (nums[target_index] > 0) {
        nums[target_index] *= -1;
      }
    }

    vector<int> disappeared_nums;
    for (int i = 1; i <= nums.size(); i++) {
      if (nums[i - 1] > 0) {
        disappeared_nums.push_back(i);
      }
    }

    return disappeared_nums;
  }
};
