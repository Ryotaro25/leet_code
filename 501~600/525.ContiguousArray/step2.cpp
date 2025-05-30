// TLE because the order is O(n^2)
class Solution {
public:
  int findMaxLength(vector<int>& nums) {
    if (nums.empty()) {
      return 0;
    }
    map<int, int> sum_to_index;
    sum_to_index[0] = -1;

    int sum = 0;
    int max_length = 0;
    for (int i = 0; i < nums.size(); i++) {
      sum += nums[i] == 1 ? 1 : -1;

      if (sum_to_index.contains(sum)) {
        max_length = max(max_length, i - sum_to_index[sum]);
        continue;
      }
      sum_to_index[sum] = i;
    }

    return max_length;
  }
};
