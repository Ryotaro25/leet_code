class Solution {
public:
  int climbStairs(int n) {
    if (n == 1) {
      return 1;
    }
    if (n == 2) {
      return 2;
    }

    int two_previous_ways = 1;
    int one_previous_ways = 2;
    int current = 0;
    for (int i = 3; i <= n; i++) {
      current = two_previous_ways + one_previous_ways;
      two_previous_ways = one_previous_ways;
      one_previous_ways = current;
    }
    return current;
  }
};
