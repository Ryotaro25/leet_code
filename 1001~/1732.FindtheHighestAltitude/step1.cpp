class Solution {
public:
  int largestAltitude(vector<int>& gain) {
    int altitude = 0;
    int max_altitude = altitude;
    for (int point : gain) {
      altitude += point;
      max_altitude = max(max_altitude, altitude);
    }

    return max_altitude;
  }
};
