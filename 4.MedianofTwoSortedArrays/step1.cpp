class Solution {
  public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
      vector<int> merged_nums;
      for (int num : nums1) {
        merged_nums.push_back(num);
      }
      for (int num : nums2) {
        merged_nums.push_back(num);
      }
      sort(merged_nums.begin(), merged_nums.end());

      if (merged_nums.size() == 1) {
        return merged_nums[0];
      }

      int middle = merged_nums.size() / 2;
      if (merged_nums.size() % 2 == 0) {
       return (static_cast<double>(merged_nums[middle]) + static_cast<double>(merged_nums[middle - 1])) / 2.0;
      } else {
        return merged_nums[middle];
      }
    }
  };
