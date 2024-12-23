class Solution {
public:
  int findMaxConsecutiveOnes(vector<int>& nums) {
    int cnt = 0;
    int max_consecutive = 0;
    for (int num : nums) {
      if (num == 1) {
        cnt++;
      } else {
        cnt = 0;
      }
      max_consecutive = max(max_consecutive, cnt);
    }

    return max_consecutive;
  }
};
