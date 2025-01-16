class Solution {
public:
  int thirdMax(vector<int>& nums) {
    sort(nums.rbegin(), nums.rend());

    int distinct_cnt = 1;
    int previous_num = nums[0];

    for (int i = 1; i < nums.size(); i++) {
      if (previous_num != nums[i]) {
        previous_num = nums[i];
        distinct_cnt++;
      }

      if (distinct_cnt == 3) {
        return nums[i];
      }
    }

    return nums[0];
  }
};
