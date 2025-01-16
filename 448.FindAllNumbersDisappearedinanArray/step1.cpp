class Solution {
public:
  vector<int> findDisappearedNumbers(vector<int>& nums) {
    set<int> distinct_nums(nums.begin(), nums.end());
    
    vector<int> disappeared_nums;
    for (int i = 1; i <= nums.size(); i++) {
      if (!distinct_nums.contains(i)) {
        disappeared_nums.push_back(i);
      }
    }

    return disappeared_nums;
  }
};
