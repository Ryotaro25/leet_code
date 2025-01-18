class Solution {
public:
  int dominantIndex(vector<int>& nums) {
    int max_num = 0;
    int target_index = -1;
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] > max_num) {
        max_num = nums[i];
        target_index = i;
      }
    }

    bool is_twice_large = true;
    for (int i = 0; i < nums.size(); i++) {
      if (i != target_index && nums[i] > max_num / 2) {
        is_twice_large = false;
        break;
      }
    }

    if (is_twice_large) {
      return target_index;
    }

    return -1;
  }
};
