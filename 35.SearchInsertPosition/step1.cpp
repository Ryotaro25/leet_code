class Solution {
public:
  int searchInsert(vector<int>& nums, int target) {
    // leftはtargetの常に左側
    // rightは、targetと同じか右側
    int left = 0;
    int right = nums.size();

    // leftが最終的に挿入位置を指していて欲しい
    // rightはtargetと同じ数字か次の数字の1番左側に来ていて欲しい
    while (left < right) {
      int middle = left + (right - left) / 2;

      if (nums[middle] < target) {
        left = middle + 1;
      } else {
        right = middle;
      }
    }

    return left;
  }
};
