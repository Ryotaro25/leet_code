class Solution {
public:
  vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    vector<vector<int>> merged_intervals;
    vector<int> merged = newInterval;
    int i = 0;

    // iterating until overlap
    while (i < intervals.size() && intervals[i][1] < merged[0]) {
      merged_intervals.push_back(intervals[i]);
      i++;
    }

    while (i < intervals.size() && intervals[i][0] <= merged[1]) {
      merged[0] = min(merged[0], intervals[i][0]);
      merged[1] = max(merged[1], intervals[i][1]);
      i++;
    }
    merged_intervals.push_back(merged);

    while (i < intervals.size()) {
      merged_intervals.push_back(intervals[i]);
      i++;
    }
    return merged_intervals;
  }
};
