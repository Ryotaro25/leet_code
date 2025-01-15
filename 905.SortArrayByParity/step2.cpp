class Solution {
public:
  vector<int> sortArrayByParity(vector<int>& nums) {
    vector<int> sorted_nums;
    for (auto num : nums) {
      if (num % 2 == 0) {
        sorted_nums.push_back(num);
      }
    }
    for (auto num : nums) {
      if (num % 2 != 0) {
        sorted_nums.push_back(num);
      }
    }

    return sorted_nums;
  }
};
