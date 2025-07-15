class Solution {
public:
  int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end());
    set<vector<int>> overlap_intervals;
    for (int i = 0; i < intervals.size() - 1; i++) {
      if (intervals[i][1] > intervals[i + 1][0]) {
        cout << intervals[i][0] << intervals[i][1] << endl;
        overlap_intervals.insert(intervals[i]);
      }
    }
    return overlap_intervals.size();
  }
};
