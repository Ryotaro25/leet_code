class Solution {
public:
  vector<int> searchRange(vector<int>& nums, int target) {
    if (nums.size() == 0) {
      return {-1, -1};
    }
    int left = SearchStartIndex(nums, target);
    int right = SearchEndIndex(nums, target);
    return {left, right};
  }

private:
  int SearchStartIndex(const vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size() - 1;

    while (left < right) {
      int middle = left + (right - left) / 2;

      if (nums[middle] < target) {
        left = middle + 1;
      } else {
        right = middle;
      }
    }

    if (nums[left] == target) {
      return left;
    } else {
      return -1;
    }
  }

  int SearchEndIndex(const vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size() - 1;

    while (left < right) {
      // 切り上げにすることで探索を右側に
      int middle = left + (right - left + 1) / 2;

      if (nums[middle] <= target) {
        left = middle;
      } else {
        right = middle - 1;
      }
    }

    if (nums[left] == target) {
      return left;
    } else {
      return -1;
    }
  }
};
