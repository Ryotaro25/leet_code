class Solution {
public:
  int dominantIndex(vector<int>& nums) {
    int max_index = 0;
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] > nums[max_index]) {
        max_index = i;
      }
    }

    for (int i = 0; i < nums.size(); i++) {
      if (i != max_index && nums[i] > nums[max_index] / 2) {
        return -1;
      }
    }

    return max_index;
  }
};
