class Solution {
  public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
      vector<int> small_nums;
      vector<int> large_nums;

      if (nums1.size() > nums2.size()) {
        large_nums = nums1;
        small_nums = nums2;
      } else {
        large_nums = nums2;
        small_nums = nums1;
      }
      sort(large_nums.begin(), large_nums.end());

      vector<int> intersect_nums;
      for (int num : small_nums) {
        int left = 0;
        int right = large_nums.size() - 1;

        while (left <= right) {
          int middle = left + (right - left) / 2;
          if (large_nums[middle] == num) {
            intersect_nums.push_back(num);
            large_nums.erase(large_nums.begin() + middle);
            break;
          }
          if (large_nums[middle] < num) {
            left = middle + 1;
          } else {
            right = middle - 1;
          }
        }
      }
      return intersect_nums;
    }
  };
