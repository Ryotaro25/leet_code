class Solution {
public:
  int mySqrt(int x) {
    if (x < 2) {
      return x;
    }

    int left = 2;
    int right = x / 2;

    while (left <= right) {
      int middle = left + (right - left) / 2;

      if (middle == x / middle) {
        return middle;
      }
      if (middle < x / middle) {
        left = middle + 1;
      } else {
        right = middle - 1;
      }
    }
    return right;
  }
};
