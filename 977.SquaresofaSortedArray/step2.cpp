class Solution {
public:
  vector<int> sortedSquares(vector<int>& nums) {
    // 二乗してから並び替えるより、絶対値をとって左右の大きい方をvectorに突っ込んでいく
    // 0(n log n) -> O(n)
    int left = 0;
    int right = nums.size() - 1;

    vector<int> squared_nums(nums.size());
    for (int i = nums.size() - 1; i >= 0; i--) {
      if (abs(nums[left]) > abs(nums[right])) {
        squared_nums[i] = pow(nums[left], 2);
        left++;
      } else {
        squared_nums[i] = pow(nums[right], 2);
        right--;
      }
    }

    return squared_nums;
  }
};
