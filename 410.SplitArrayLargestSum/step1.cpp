class Solution {
public:
  int splitArray(vector<int>& nums, int k) {
    int max_num = 0;
    int sum_num = 0;
    for (auto num : nums) {
      max_num = max(max_num, num);
      sum_num += num;
    }
    cout << max_num << " " << sum_num << endl;

    return SearchMinLargestSum(nums, max_num, sum_num, k);
  }

private:
  int SearchMinLargestSum(vector<int>& nums, int max_num, int sum_num, int divide_cnt) {
    int left = max_num;
    int right = sum_num;
    while (left < right) {
      int middle = left + (right - left) / 2;

      if (IsDivadable(nums, middle, divide_cnt)) {
        right = middle;
      } else {
        left = middle + 1;
      }
    }

    return left;
  }

  bool IsDivadable(vector<int>& nums, int largest_sum, int k) {
    int cnt = 1;
    int total_num = 0;
    for (auto num : nums) {
      total_num += num;
      if (total_num > largest_sum) {
        total_num = num;
        cnt++;
      }
    }

    return cnt <= k;
  }
};
