class Solution {
public:
  bool canAttendMeetings(vector<vector<int>>& intervals) {
    map<int, int> hour_to_key;
    for (auto interval : intervals) {
      hour_to_key[interval[0]]++;
      hour_to_key[interval[1]]--;
    }

    int sum_key = 0;
    for (auto [hour, using_key] : hour_to_key) {
      sum_key += using_key;
      if (sum_key > 1) {
        return false;
      }
    }
    return true;
  }
};
