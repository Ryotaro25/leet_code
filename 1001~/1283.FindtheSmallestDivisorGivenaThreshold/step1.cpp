class Solution {
public:
  int smallestDivisor(vector<int>& nums, int threshold) {
    int left = 1;
    int right = 0;
    for (int num : nums) {
      right = max(num, right);
    }

    while (left < right) {
      int middle = left + (right - left) / 2;

      if (IsLessOrEqual(nums, threshold, middle)) {
        right = middle;
      } else {
        left = middle + 1;
      }
    }

    return left;
  }

private:
  bool IsLessOrEqual(vector<int>& nums, int threshold, int divisor) {
    int sum = 0;
    for (int num : nums) {
      sum += ((num + divisor - 1) / divisor);
    }

    return sum <= threshold;
  }
};
