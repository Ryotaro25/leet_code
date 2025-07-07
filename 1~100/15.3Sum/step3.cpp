class Solution {
public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    set<vector<int>> unique_triplet;
    set<int> visited;
    for (int i = 0; i < nums.size(); i++) {
      if (visited.contains(nums[i])) {
        continue;
      }
      visited.insert(nums[i]);

      set<int> seen_so_far;
      for (int j = i + 1; j < nums.size(); j++) {
        int compliment = -nums[i] - nums[j];
        if (!seen_so_far.contains(compliment)) {
          seen_so_far.insert(nums[j]);
          continue;
        }
        vector<int> triplet = {nums[i], nums[j], compliment};
        sort(triplet.begin(), triplet.end());
        unique_triplet.insert(triplet);
      }
    }
    return vector<vector<int>>(unique_triplet.begin(), unique_triplet.end());
  }
};
