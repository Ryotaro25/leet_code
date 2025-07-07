class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
      set<vector<int>> unique_triplets;
      set<int> visited;
      for (int i = 0; i < nums.size(); i++) {
        if (visited.contains(nums[i])) {
          continue;
        }
        visited.insert(nums[i]);
        set<int> seen;
        for (int j = i + 1; j < nums.size(); j++) {
          int compliment = -nums[i] - nums[j];
          if (seen.contains(compliment)) {
            vector<int> triplet = {nums[i], nums[j], compliment};
            sort(triplet.begin(), triplet.end());
            unique_triplets.insert(triplet);
          }
          seen.insert(nums[j]);
        }
      }
      vector<vector<int>> results(unique_triplets.begin(), unique_triplets.end());
      return results;
    }
};
