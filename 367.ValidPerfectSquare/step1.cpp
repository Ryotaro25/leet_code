class Solution {
  public:
    bool isPerfectSquare(int num) {
      if (num == 1) {
        return true;
      }
      int left = 1;
      int right = num / 2 + 1;

      while (left < right) {
        int middle = left + (right - left) / 2;
        long sqared = static_cast<long>(middle) * static_cast<long>(middle);
        if (sqared == static_cast<long>(num)) {
          return true;
        }
        if (sqared < static_cast<long>(num)) {
          left = middle + 1;
        } else {
          right = middle;
        }
      }

      return false;
    }
  };
