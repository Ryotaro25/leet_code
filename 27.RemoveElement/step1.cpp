class Solution {
public:
  int removeElement(vector<int>& nums, int val) {
    vector<int> removed_nums;
    for (auto num : nums) {
      if (num != val) {
        removed_nums.push_back(num);
      }
    }

    nums = removed_nums;
    return nums.size();
  }
};
