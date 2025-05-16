class Solution {
public:
  int smallestDistancePair(vector<int>& nums, int k) {
    vector<int> sorted_nums = nums;
    sort(sorted_nums.begin(), sorted_nums.end());
    int min_num = 0;
    int max_num = sorted_nums.back() - sorted_nums[0];

    while (min_num < max_num) {
      int middle = min_num + (max_num - min_num) / 2;

      if (CheckValidPairs(sorted_nums, k, middle)) {
        max_num = middle;
      } else {
        min_num = middle + 1;
      }
    }

    return min_num;
  }

private:
  bool CheckValidPairs(vector<int>& nums, int k, int middle) {
    int fast = 0;
    int slow = 0;
    int cnt = 0;
    while (fast < nums.size()) {
      while (nums[fast] - nums[slow] > middle) {
        slow++;
      }
      cnt += (fast - slow);  // slow から fast-1 までのペア数を加算
      fast++;
    }

    return cnt >= k;
  }
};
