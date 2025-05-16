class Solution {
public:
  int UNDEFINED = -1;

  int deleteAndEarn(vector<int>& nums) {
    map<int, int> nums_to_points;
    int max_num = 0;
    for (auto num : nums) {
      nums_to_points[num] += num;
      max_num = max(max_num, num);
    }

    vector<int> max_point_so_far(max_num + 1, UNDEFINED);
    return CalcMaxPoint(max_num, nums_to_points, max_point_so_far);
  }

private:
  int CalcMaxPoint(const int num, map<int, int> &nums_to_points, vector<int> &max_point_so_far) {
    if (num <= 0) {
      return 0;
    }

    if (max_point_so_far[num] != UNDEFINED) {
      return max_point_so_far[num];
    }

    int gain = 0;
    if (nums_to_points.contains(num)) {
      gain = nums_to_points[num];
    }

    max_point_so_far[num] = max(CalcMaxPoint(num - 2, nums_to_points, max_point_so_far) + gain, 
                                CalcMaxPoint(num - 1, nums_to_points, max_point_so_far));
    return max_point_so_far[num];
  }
};
