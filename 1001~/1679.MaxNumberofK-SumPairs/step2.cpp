class Solution {
public:
  int maxOperations(vector<int>& nums, int k) {
    map<int, int> num_to_cnt;
    for (auto num : nums) {
      num_to_cnt[num]++;
    }

    int num_operations = 0;
    for (auto num : nums) {
      int compliment = k - num;
      if (!num_to_cnt.contains(compliment)) {
        continue;
      }
      if (num_to_cnt[num] > 0 && num_to_cnt[compliment] > 0) {
        if (num == compliment && num_to_cnt[num] < 2) {
          continue;
        }
        num_operations++;
        num_to_cnt[num]--;
        num_to_cnt[compliment]--;
      }
    }

    return num_operations;
  }
};