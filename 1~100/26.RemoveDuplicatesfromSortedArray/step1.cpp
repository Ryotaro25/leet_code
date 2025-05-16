class Solution {
public:
  int removeDuplicates(vector<int>& nums) {
    int i = 1;
    // don't need to use additional space
    int val = nums[0];
    for (int j = 1; j < nums.size(); j++) {
      if (nums[j] != val) {
        nums[i] = nums[j];
        val = nums[j];
        i++;
      }
    }

    return i;
  }
};
