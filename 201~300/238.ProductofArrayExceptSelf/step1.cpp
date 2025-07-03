class Solution {
public:
  vector<int> productExceptSelf(vector<int>& nums) {
    vector<int> products_except_self(nums.size(), 1);
    for (int i = 0; i < nums.size(); i++) {
      for (int j = 0; j < nums.size(); j++) {
        if (i == j) {
          continue;
        }
        products_except_self[i] *= nums[j];
      }
    }
    return products_except_self;
  }
};