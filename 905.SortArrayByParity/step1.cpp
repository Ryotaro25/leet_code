// im place solution
class Solution {
public:
  vector<int> sortArrayByParity(vector<int>& nums) {
    int even_index = 0;
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] % 2 == 0) {
        swap(nums[even_index], nums[i]);
        even_index++;
      }
    }

    return nums;
  }
};
