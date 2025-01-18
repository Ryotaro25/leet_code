class Solution {
public:
  int dominantIndex(vector<int>& nums) {
    int max_num = 0;
    for (auto num : nums) {
      max_num = max(max_num, num);
    }

    bool is_twice_large = true;
    int target_index = -1;
    for (int i = 0; i < nums.size(); i++) {
      cout << nums[i] << " max is" << max_num << endl;
      if (nums[i] * 2 <= max_num) {
        is_twice_large = false;
      }
      if (nums[i] == max_num) {
        target_index = i;
      }
    }

    if (is_twice_large) {
      return target_index;
    }

    return -1;
  }
};
