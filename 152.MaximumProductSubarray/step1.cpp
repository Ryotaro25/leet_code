class Solution {
public:
  int maxProduct(vector<int>& nums) {
    if (nums.empty()) {
      return 0;
    }
    int max_product = std::numeric_limits<int>::min();
    for (int i = 0; i < nums.size(); i++) {
      int product = 1;
      for (int j = i; j < nums.size(); j++) {
        product *= nums[j];
        max_product = max(max_product, product);
      }
    }
    return max_product;
  }
};
