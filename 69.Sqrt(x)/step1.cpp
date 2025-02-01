class Solution {
public:
  int mySqrt(int x) {
    if (x == 0) {
      return 0;
    }
    if (x == 1) {
      return 1;
    }
 
    int left = 0;
    int right = x;

    while (left < right) {
      int middle = left + (right - left) / 2;

      if (static_cast<long>(middle) * static_cast<long>(middle) < static_cast<long>(x)) {
        left = middle + 1;
      } else {
        right = middle;
      }
    }

    return left;
  }
};
