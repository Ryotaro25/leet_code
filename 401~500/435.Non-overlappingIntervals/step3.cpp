class Solution {
public:
  int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end(), CompareSecondElement);
    int num_overlap = 0;
    int prev_end = numeric_limits<int>::min();
    for (auto interval : intervals) {
      if (interval[0] < prev_end) {
        num_overlap++;
      } else {
        prev_end = interval[1];
      }
    }

    return num_overlap;
  }

private:
  static bool CompareSecondElement(vector<int>& interval, vector<int>& other_interval) {
    return interval[1] < other_interval[1];
  }
};
