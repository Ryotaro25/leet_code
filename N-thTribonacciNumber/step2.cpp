class Solution {
public:
  int tribonacci(int n) {
    map<int, int> int_to_value;
    return CalcTribonacci(n, int_to_value);
  }

private:
  int CalcTribonacci(int n, map<int, int> &memo) {
    if (memo.contains(n)) {
      return memo[n];
    }
    if (n == 0) {
      return 0;
    }
    if (n == 1 || n == 2) {
      return 1;
    }
    memo[n] = CalcTribonacci(n - 1, memo) + CalcTribonacci(n - 2, memo) + CalcTribonacci(n - 3, memo);
    return memo[n];
  }
};
