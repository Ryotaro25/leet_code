class Solution {
public:
  int pivotIndex(vector<int>& nums) {
    int left_sum = 0;
    for (int pivot = 0; pivot < nums.size(); pivot++) {
      int right_sum = 0;
      for (int i = pivot + 1; i < nums.size(); i++) {
        right_sum += nums[i];
      }
      if (left_sum == right_sum) {
        return pivot;
      }
      left_sum += nums[pivot];
    }
    return NOANSWER;
  }

private:
  static constexpr int NOANSWER = -1;
};
