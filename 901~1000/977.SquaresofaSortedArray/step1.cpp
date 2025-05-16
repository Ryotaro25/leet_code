class Solution {
public:
  vector<int> sortedSquares(vector<int>& nums) {
    vector<int> squared_nums;
    for (int num : nums) {
      squared_nums.push_back(pow(num, 2));
    }
    sort(squared_nums.begin(), squared_nums.end());
    return squared_nums;
  }
};
