class Solution {
public:
  int findNumbers(vector<int>& nums) {
    int cnt = 0;
    for (auto num : nums) {
      int digit = 0;
      while (num > 0) {
        digit++;
        num /= 10;
      }
      if (digit % 2 == 0) {
        cnt++;
      }
    }

    return cnt;
  }
};
