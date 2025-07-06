class Solution {
public:
  int longestConsecutive(vector<int>& nums) {
    if (nums.empty()) {
      return 0;
    }
    set<int> unique_numbers(nums.begin(), nums.end());

    int num_longest_length = 1;
    int current_length = 1;
    int prev_num = *unique_numbers.begin();
    for (auto it = next(unique_numbers.begin()); it != unique_numbers.end(); it++) {
      if (prev_num + 1 == *it) {
        current_length++;
      } else {
        current_length = 1; 
      }
      prev_num = *it;
      num_longest_length = max(num_longest_length, current_length);
    }
    return num_longest_length;
  }
};
