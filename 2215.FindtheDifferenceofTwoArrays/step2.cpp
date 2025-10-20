class Solution {
public:
  vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
    if (nums1.empty() || nums2.empty()) {
      return {};
    }

    return {GetElementsNotInSecond(nums1, nums2), GetElementsNotInSecond(nums2, nums1),};
  }

private:
  vector<int> GetElementsNotInSecond(const vector<int>& first_nums, const vector<int>& second_nums) {
    set<int> nums_to_exclude(second_nums.begin(), second_nums.end());
    set<int> unique_to_first;
    for (int num : first_nums) {
      if (nums_to_exclude.contains(num)) {
        continue;
      }
      unique_to_first.insert(num);
    }
    return {unique_to_first.begin(), unique_to_first.end()};
  }
};
