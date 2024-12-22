class Solution {
public:
  int deleteAndEarn(vector<int>& nums) {
    map<int, int> nums_to_points;
    int max_number = 0;
    for (auto num : nums) {
      nums_to_points[num] += num;
      max_number = max(max_number, num);
    }

    int two_step_back_max = 0;
    int one_step_back_max = 0;
    if (nums_to_points.contains(1)) {
      one_step_back_max = nums_to_points[1];
    }

    for (int i = 2; i <= max_number; i++) {
      int gain = 0;
      if (nums_to_points.contains(i)) {
        gain = nums_to_points[i];
      }
      int temp = one_step_back_max;
      one_step_back_max = max(one_step_back_max, two_step_back_max + gain);
      two_step_back_max = temp;
    }

    return max(two_step_back_max, one_step_back_max);
    
  }
};