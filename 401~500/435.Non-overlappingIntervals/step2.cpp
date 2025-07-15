class Solution {
public:
  int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end(), CompareSecond);
    int prev_end = numeric_limits<int>::min();
    int num_overlap = 0;
    for (int i = 0; i < intervals.size(); i++) {
      if (intervals[i][0] < prev_end) {
        num_overlap++;
      } else {
        prev_end = intervals[i][1];
      }
    }
    return num_overlap;
  }

private:
  static bool CompareSecond(vector<int>& interval, vector<int>& other_interval) {
    return interval[1] < other_interval[1];
  }
};
