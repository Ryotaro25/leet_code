class Solution {
public:
  int mySqrt(int x) {
    if (x < 2) {
      return x;
    }

    long left = 2;
    long right = x / 2;

    while (left <= right) {
      long middle = left + (right - left) / 2;
      long square = middle * middle;

      if (square == x) {
        return middle;
      }
      if (square < x) {
        left = middle + 1;
      } else {
        right = middle - 1;
      }
    }
    return right;
  }
};
