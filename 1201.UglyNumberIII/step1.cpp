class Solution {
public:
  int nthUglyNumber(int n, int a, int b, int c) {
    long long min_number = 1;
    long long max_number = min({a, b, c}) * static_cast<long long>(n);

    while (min_number < max_number) {
      long long middle = min_number + (max_number - min_number) / 2;

      if (IsOvernth(n, a, b, c, middle)) {
        max_number = middle;
      } else {
        min_number = middle + 1;
      }
    }

    return min_number;
  }

private:
  bool IsOvernth(long long n, long long a, long long b, long long c, long long target_num) {
    long long total = 0;
    total += target_num / a;
    total += target_num / b;
    total += target_num / c;
    total -= target_num / lcm(a, b);
    total -= target_num / lcm(b, c);
    total -= target_num / lcm(c, a);
    total += target_num / lcm(a, lcm(b, c));

    return total >= n;
  } 
};
