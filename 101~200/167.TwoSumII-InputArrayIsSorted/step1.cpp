class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
      for (int i = 0; i < numbers.size(); i++) {
        int remain = target - numbers[i];

        int left = i + 1;
        int right = numbers.size() - 1;
        while (left <= right) {
          int middle = left + (right - left) / 2;
          if (numbers[middle] == remain) {
            return {i + 1, middle + 1};
          }
          if (numbers[middle] < remain) {
            left = middle + 1;
          } else {
            right = middle;
          }
        }
      }
      return {-1, -1};
    }
};
