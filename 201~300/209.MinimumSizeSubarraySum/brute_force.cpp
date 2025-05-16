// time limit exceeded
class Solution {
public:
  int minSubArrayLen(int target, vector<int>& nums) {
    int min_length = NOANSWER;
    for (int i = 0; i < nums.size(); i++) {
      int remain = target - nums[i];
      int cnt = 1;
      
      int j = i + 1;
      while (remain > 0 && j < nums.size()) {
        remain -= nums[j];
        j++;
        cnt++;
      }
      
      if (remain <= 0) {
        min_length = min(min_length, cnt);
      }
    }

    if (min_length != NOANSWER) {
      return min_length;
    } else {
      return 0;
    }
  }

private:
  static constexpr int NOANSWER = numeric_limits<int>::max();
};
