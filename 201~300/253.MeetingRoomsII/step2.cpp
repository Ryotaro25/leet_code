class Solution {
public:
  int minMeetingRooms(vector<vector<int>>& intervals) {
    map<int, int> hour_to_using_room;
    for (const vector<int>& interval : intervals) {
      hour_to_using_room[interval[0]]++;
      hour_to_using_room[interval[1]]--;
    }

    int num_required_room = 0;
    int num_using_room = 0;
    for (auto [hour, room] : hour_to_using_room) {
      num_using_room += room;
      num_required_room = max(num_required_room, num_using_room);
    } 
    return num_required_room;
  }
};
