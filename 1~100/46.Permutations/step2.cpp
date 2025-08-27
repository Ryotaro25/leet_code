class Solution {
public:
  vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> all_permutations;
    vector<int> permutation;
    set<int> used;
    GeneratePermutations(nums, all_permutations, permutation, used);
    return all_permutations;
  }

private:
  void GeneratePermutations(vector<int>& nums, vector<vector<int>>& all_permutations,
                       vector<int>& permutation, set<int>& used) {
    if (permutation.size() == nums.size()) {
      all_permutations.emplace_back(permutation);
      return;
    }

    for (int num : nums) {
      if (used.contains(num)) {
        continue;
      }
      used.insert(num);
      permutation.push_back(num);
      GeneratePermutations(nums, all_permutations, permutation, used);
      used.erase(num);
      permutation.pop_back();
    }
  }
};
