class Solution {
public:
  vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    vector<vector<int>> modified_intervals;
    vector<int> merged_interval = newInterval;
    for (int i = 0; i < intervals.size(); i++) {
      if (intervals[i][1] >= merged_interval[0]) {
        merged_interval[0] = min(merged_interval[0], intervals[i][0]);

        int overlap_idx = i;
        while (overlap_idx < intervals.size() && intervals[i][1] >= merged_interval[0]) {
          merged_interval[1] = max(merged_interval[1], intervals[i][1]);
          overlap_idx++;
        }
        cout << merged_interval[0] << merged_interval[1] << endl;
        modified_intervals.push_back(merged_interval);
        i = overlap_idx - 1;
      }
      modified_intervals.push_back(intervals[i]);
    }
    return modified_intervals;
  }
};