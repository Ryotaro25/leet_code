class Solution {
public:
  void rotate(vector<int>& nums, int k) {
    int cnt = 0;
    while (cnt < k) {
      for (int i = nums.size() - 1; i > 0; i--) {
        swap(nums[i], nums[i - 1]);
      }
      cnt++;
    }
  }
};

