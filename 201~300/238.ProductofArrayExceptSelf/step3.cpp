class Solution {
public:
  vector<int> productExceptSelf(vector<int>& nums) {
    vector<int> products_from_left(nums.size(), 1);
    for (int i = 0; i < nums.size() - 1; i++) {
      products_from_left[i + 1] = products_from_left[i] * nums[i];
    }

    vector<int> products_from_right(nums.size(), 1);
    for (int i = nums.size() - 1; i > 0; i--) {
      products_from_right[i - 1] = products_from_right[i] * nums[i];
    }

    vector<int> products_except_self(nums.size());
    for (int i = 0; i < nums.size(); i++) {
      products_except_self[i] = products_from_left[i] * products_from_right[i];
    }
    return products_except_self;
  }
};
