class Solution {
public:
  bool increasingTriplet(vector<int>& nums) {
    for (int i = 0; i < nums.size(); i++) {
      for (int j = i; j < nums.size(); j++) {
        for (int k = j; k < nums.size(); k++) {
          if (nums[i] < nums[j] && nums[j] < nums[k]) {
            return true;
          }
        }
      }
    }

    return false;
  }
};
