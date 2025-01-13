class Solution {
public:
  void moveZeroes(vector<int>& nums) {
    vector<int> moved_nums;
    int zero_cnt = 0;
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] != 0) {
        moved_nums.push_back(nums[i]);
        continue;
      }
      zero_cnt++;
    }
    
    while (zero_cnt) {
      moved_nums.push_back(0);
      zero_cnt--;
    }

    nums = moved_nums;
  }
};
