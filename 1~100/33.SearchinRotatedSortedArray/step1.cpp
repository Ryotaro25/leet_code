class Solution {
public:
  int search(vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size();
    int min_index = FindMinIndex(nums);

    int target_index = SearchTarget(nums, target, left, min_index - 1);
    if (target_index != -1) {
      return target_index;
    }
    return SearchTarget(nums, target, min_index, right - 1);
  }

private:
  int FindMinIndex(vector<int>& nums) {
    int left = 0;
    int right = nums.size() - 1;

    while (left < right) {
      int middle = left + (right - left) / 2;

      if (nums[middle] > nums[right]) {
        left = middle + 1;
      } else {
        right = middle;
      }
    }
    return left;
  }

  int SearchTarget(vector<int>& nums, int target, int left, int right) {
    while (left <= right) {
      int middle = left + (right - left) / 2;

      if (nums[middle] == target) {
        return middle;
      }
      if (nums[middle] < target) {
        left = middle + 1;
      } else {
        right = middle - 1;
      }
    }

    return -1;
  }
};
