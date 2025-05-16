class Solution {
public:
  int search(vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size() - 1;
    return SearchIndex(nums, target, left, right);
  }

private:
  int SearchIndex(vector<int>& nums, int target, int left, int right) {
    if (left > right) {
      return -1;
    }

    int middle = left + (right - left) / 2;
    if (nums[middle] == target) {
      return middle;
    }

    if (nums[middle] < target) {
      return SearchIndex(nums, target, middle + 1, right);
    } else {
      return SearchIndex(nums, target, left, middle - 1);
    }
  }
};
