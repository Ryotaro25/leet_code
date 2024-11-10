class Solution {
public:
  int maximumScore(vector<int>& nums, vector<int>& multipliers) {
    vector<vector<int>> memo(multipliers.size() + 1, vector<int>(multipliers.size() + 1));
    
    for (int i = multipliers.size() - 1; i >= 0; i--) {
      for (int left = i; left >= 0; left--) {
        int mult = multipliers[i];
        int right = nums.size() - 1 - (i - left);

        memo[i][left] = max(mult * nums[left] + memo[i + 1][left + 1],
                            mult * nums[right] + memo[i + 1][left]);
      }
    }

    return memo[0][0];
  }
};

