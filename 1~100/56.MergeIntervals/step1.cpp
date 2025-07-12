class Solution {
public:
  vector<vector<int>> merge(vector<vector<int>>& intervals) {
    if (intervals.empty() || intervals[0].empty()) {
      return {};
    }
    sort(intervals.begin(), intervals.end());

    vector<vector<int>> merged_intervals;
    for (int i = 0; i < intervals.size(); i++) {
      vector<int> overlap = intervals[i];
      while (i < intervals.size() - 1 && overlap[1] >= intervals[i + 1][0]) {
        overlap[0] = min(overlap[0], intervals[i + 1][0]);
        overlap[1] = max(overlap[1], intervals[i + 1][1]);
        i++;
      }
      merged_intervals.push_back(overlap);
    }
    return merged_intervals;
  }
};
