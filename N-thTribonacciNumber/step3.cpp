class Solution {
public:
  const int UNDEFINED = -1;
  int tribonacci(int n) {
    vector<int> values(n + 1, UNDEFINED);
    return CalcTribonacci(n, values);
  }

private:
  int CalcTribonacci(const int n, vector<int> &values) {
    if (values[n] != UNDEFINED) {
      return values[n];
    }
    if (n == 0) {
      return 0;
    }
    if (n == 1 || n == 2) {
      return 1;
    }
    values[n] = CalcTribonacci(n - 1, values) + CalcTribonacci(n - 2, values) + CalcTribonacci(n - 3, values);
    return values[n];
  }
};
