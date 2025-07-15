class Solution {
public:
  int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    // 終了時刻が早い区間を優先的に残すと、後の区間との重複が少なくなる
    sort(intervals.begin(), intervals.end(), CompareSecondElement);
    int num_overlap = 0;
    int later_endtime = numeric_limits<int>::min();
    for (int i = 0; i < intervals.size(); i++) {
      if (intervals[i][0] < later_endtime) {
        num_overlap++;
      } else {
        later_endtime = intervals[i][1];
      }
    }
    
    return num_overlap;
  }

private:
  static bool CompareSecondElement(vector<int>& interval, vector<int>& other_interval) {
    return interval[1] < other_interval[1];
  }
};
