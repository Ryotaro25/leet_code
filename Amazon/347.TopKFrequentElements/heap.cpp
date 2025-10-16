class Solution {
public:
  vector<int> topKFrequent(vector<int>& nums, int k) {
    map<int, int> num_to_frequency;
    for (int num : nums) {
      num_to_frequency[num]++;
    }

    priority_queue<pair<int, int>> min_heap;
    
  }
};