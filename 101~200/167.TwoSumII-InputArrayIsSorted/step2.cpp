class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
      int left = 0;
      int right = numbers.size() - 1;
      while (left < right) {
        int sum_number = numbers[left] + numbers[right];
        if (sum_number == target) {
          return {left + 1, right + 1};
        }
        if (sum_number < target) {
          left++;
        } else {
          right--;
        }
      }
      return {-1, -1};
    }
};
