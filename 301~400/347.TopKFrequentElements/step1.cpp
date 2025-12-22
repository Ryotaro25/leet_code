class Solution {
public:
  vector<int> topKFrequent(vector<int>& nums, int k) {
    map<int, int> num_to_frequency;
    for (int num : nums) {
      num_to_frequency[num]++;
    }

    map<int, vector<int>> frequency_to_nums;
    for (auto [num, frequency] : num_to_frequency) {
      frequency_to_nums[frequency].push_back(num);
    }

    vector<int> top_k_frequent_nums;
    for (auto it = frequency_to_nums.rbegin(); it != frequency_to_nums.rend(); it++) {
      for (auto num : it->second) {
        if (top_k_frequent_nums.size() < k) {
          top_k_frequent_nums.push_back(num);
        }
      }
    }
    return top_k_frequent_nums;
  }
};
