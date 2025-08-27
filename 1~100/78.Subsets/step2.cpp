class Solution {
public:
  vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> all_subsets;
    vector<int> subset;
    GenerateSubsets(nums, 0, all_subsets, subset);
    return all_subsets;
  }

private:
  void GenerateSubsets(vector<int>& nums, int start, vector<vector<int>>& all_subsets, vector<int>& subset) {
    all_subsets.emplace_back(subset);

    for (int i = start; i < nums.size(); i++) {
      subset.push_back(nums[i]);
      GenerateSubsets(nums, i + 1, all_subsets, subset);
      subset.pop_back();
    }
  }
};
