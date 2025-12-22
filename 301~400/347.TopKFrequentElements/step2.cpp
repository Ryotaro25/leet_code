class Solution {
public:
  vector<int> topKFrequent(vector<int>& nums, int k) {
    map<int, int> num_to_frequency;
    for (int num : nums) {
      num_to_frequency[num]++;
    }

    map<int, vector<int>> frequency_to_nums;
    for (auto [num, freq] : num_to_frequency) {
      frequency_to_nums[freq].push_back(num);
    }

    vector<int> k_frequent_nums;
    for (auto it = frequency_to_nums.rbegin(); it != frequency_to_nums.rend(); it++) {
      for (int num : it->second) {
        if (k_frequent_nums.size() < k) {
          k_frequent_nums.push_back(num);
        }
      }
    }
    return k_frequent_nums;
  }
};
