class Solution {
public:
  int smallestDistancePair(vector<int>& nums, int k) {
    vector<int> sorted_nums = nums;
    sort(sorted_nums.begin(), sorted_nums.end());
    int min_distance = 0;
    int max_distance = sorted_nums.back() -  sorted_nums[0];

    while (min_distance < max_distance) {
      int middle = min_distance + (max_distance - min_distance) / 2;

      if (AreValidPaires(sorted_nums, k, middle)) {
        max_distance = middle;
      } else {
        min_distance = middle + 1;
      }
    }

    return min_distance;
  }

private:
  bool AreValidPaires(vector<int>& nums, int k, int middle) {
    int fast = 0;
    int slow = 0;
    int cnt = 0;

    while (fast < nums.size()) {
      while (nums[fast] - nums[slow] > middle) {
        slow++;
      }
      cnt += (fast - slow);
      fast++;
    }

    return cnt >= k;
  }
};
