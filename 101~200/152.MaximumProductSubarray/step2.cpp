class Solution {
public:
  int maxProduct(vector<int>& nums) {
    if (nums.empty()) {
      return 0;
    }
    int max_so_far = nums[0];
    int min_so_far = nums[0];
    int max_product = nums[0];
 
    for (int i = 1; i < nums.size(); i++) {
      int current_max = max(nums[i], max(max_so_far * nums[i], min_so_far * nums[i]));
      min_so_far = min(nums[i], min(max_so_far * nums[i], min_so_far * nums[i]));
      
      max_so_far = current_max;
      max_product = max(max_product, max_so_far);
    }
    return max_product;
  }
};
