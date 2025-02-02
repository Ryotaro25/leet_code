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
  int SearchMinLargestSum(vector<int>& nums, int low_num, int high_num, int max_num_subarray) {
    while (low_num < high_num) {
      int middle = low_num + (high_num - low_num) / 2;

      if (IsDivadable(nums, middle, max_num_subarray)) {
        high_num = middle;
      } else {
        low_num = middle + 1;
      }
    }

    return low_num;
  }

  bool IsDivadable(vector<int>& nums, int largest_sum, int max_num_subarray) {
    int subarray_cnt = 1;
    int total_num = 0;
    for (auto num : nums) {
      total_num += num;
      if (total_num > largest_sum) {
        total_num = num;
        subarray_cnt++;
      }
    }

    return subarray_cnt <= max_num_subarray;
  }
};
