class Solution {
  public:
    bool isPerfectSquare(int num) {
      int target = num;
      int consecutive = 1;

      while (target > 0) {
        target = target - consecutive;
        consecutive += 2;
      }

      return target == 0;
    }
  };