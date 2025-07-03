class Solution {
public:
  // TLE
  int climbStairs(int n) {
    return CalcWays(0, n);
  }

private:
  int CalcWays(int i, int num_steps) {
    if (i > num_steps) {
      return 0;
    }
    if (i == num_steps) {
      return 1;
    }
    return CalcWays(i + 1, num_steps) + CalcWays(i + 2, num_steps);
  }
};
