class Solution {
public:
  int pivotIndex(vector<int>& nums) {
    int sum = 0;
    for (auto num : nums) {
      sum += num;
    }

    int left_sum = 0;
    for (int i = 0; i < nums.size(); i++) {
      int right_sum = sum - left_sum - nums[i];
      if (left_sum == right_sum) {
        return i;
      }

      left_sum += nums[i];
    }

    return NOANSWER;
  }

private:
  static constexpr int NOANSWER = -1;
};
