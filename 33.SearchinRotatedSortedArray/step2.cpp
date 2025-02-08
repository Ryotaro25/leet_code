class Solution {
public:
  int search(vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size() - 1;
    int min_index = FindMinIndex(nums);

    int target_index = FindTarget(nums, target, left, min_index - 1);
    if (target_index != -1) {
      return target_index;
    }
    return FindTarget(nums, target, min_index, right);
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

  int FindTarget(vector<int>& nums, int target, int left, int right) {
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
