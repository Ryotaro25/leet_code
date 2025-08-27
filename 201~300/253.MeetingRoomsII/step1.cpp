class Solution {
public:
  int minMeetingRooms(vector<vector<int>>& intervals) {
    map<int, int> time_to_reserved_room;
    for (auto interval : intervals) {
      time_to_reserved_room[interval[0]]++;
      time_to_reserved_room[interval[1]]--;
    }

    int min_required_room = 0;
    int num_reserved_room = 0;
    for (auto [hour, room] : time_to_reserved_room) {
      num_reserved_room += room;
      min_required_room = max(min_required_room, num_reserved_room);
    }
    return min_required_room;
  }
};
