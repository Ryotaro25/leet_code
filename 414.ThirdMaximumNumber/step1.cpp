class Solution {
public:
  int thirdMax(vector<int>& nums) {
    set<int> distinct_nums(nums.begin(), nums.end());

    if (distinct_nums.size() < 3) {
      return *distinct_nums.rbegin();
    }

    int cnt = 0;
    int third_max_num = 0;
    for (auto it = distinct_nums.rbegin(); it != distinct_nums.rend(); it++) {
      if (cnt < 3) {
        third_max_num = *it;
        cnt++;
      }
    }

    return third_max_num;
  }
};
