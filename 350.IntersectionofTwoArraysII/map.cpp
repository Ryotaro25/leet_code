class Solution {
  public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
      map<int, int> num_to_count;
      for (int num : nums1) {
        num_to_count[num]++;
      }

      vector<int> intersect_nums;
      for (int num : nums2) {
        if (num_to_count[num] > 0) {
          intersect_nums.push_back(num);
          num_to_count[num]--;
        }
      }
      return intersect_nums;
    }
  };
