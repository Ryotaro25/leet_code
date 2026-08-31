class Solution {
public:
  int maximumScore(vector<int>& nums, vector<int>& multipliers) {
    nums_g = nums;
    multipliers_g = multipliers;
    n_size = nums.size();
    m_size = multipliers.size();
    vector<vector<int>> init_memo(m_size, vector<int>(m_size));
    memo = init_memo;

    return CalMax(0, 0);
  }

private:
  vector<vector<int>> memo;
  vector<int> nums_g;
  int n_size;
  vector<int> multipliers_g;
  int m_size;

  int CalMax(int i, int left) {
    if (i == m_size) {
      return 0;
    }
    int mult = multipliers_g[i];
    int right = n_size - 1 - (i - left);

    if (memo[i][left] == 0) {
      memo[i][left] = max(mult * nums_g[left] + CalMax(i + 1, left + 1),
                          mult * nums_g[right] + CalMax(i + 1, left));
    }

    return memo[i][left];
  }
};
