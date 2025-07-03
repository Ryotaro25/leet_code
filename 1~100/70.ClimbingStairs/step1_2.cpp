class Solution {
public:
  int climbStairs(int n) {
    if (n == 1) {
      return 1;
    }
    if (n == 2) {
      return 2;
    }
    vector<int> ways_for_each_step(n + 1);
    ways_for_each_step[1] = 1;
    ways_for_each_step[2] = 2;
    for (int i = 3; i <= n; i++) {
      ways_for_each_step[i] = ways_for_each_step[i - 2] + ways_for_each_step[i - 1];
    }
    return ways_for_each_step.back();
  }
};
