class Solution {
public:
  int tribonacci(int n) {
    if (n == 0) {
      return 0;
    }
    if (n == 1 || n == 2) {
      return 1;
    }
    vector<int> calcurated_numbers(n + 1);
    calcurated_numbers[0] = 0;
    calcurated_numbers[1] = 1;
    calcurated_numbers[2] = 1;

    for (int i = 3; i <= n; i++) {
      calcurated_numbers[i] = calcurated_numbers[i - 3] + calcurated_numbers[i - 2] + calcurated_numbers[i - 1];
    }

    return calcurated_numbers[n];
  }
};
