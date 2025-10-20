class Solution {
public:
  vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
    if (nums1.empty() || nums2.empty()) {
      return {};
    }
    set<int> unique_nums1(nums1.begin(), nums1.end());
    set<int> unique_nums2(nums2.begin(), nums2.end());
    
    set<int> used_nums1;
    vector<int> distinct_nums1;
    for (int num : nums1) {
      if (unique_nums2.contains(num)) {
        continue;
      }
      if (used_nums1.contains(num)) {
        continue;
      }
      distinct_nums1.push_back(num);
      used_nums1.insert(num);
    }

    set<int> used_nums2;
    vector<int> distinct_nums2;
    for (int num : nums2) {
      if (unique_nums1.contains(num)) {
        continue;
      }
      if (used_nums2.contains(num)) {
        continue;
      }
      distinct_nums2.push_back(num);
      used_nums2.insert(num);
    }

    return {distinct_nums1, distinct_nums2};
  }
};
