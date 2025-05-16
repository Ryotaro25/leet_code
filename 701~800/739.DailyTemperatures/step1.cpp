// NG
class Solution {
  public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
      vector<int> distances;
      for (int i = 0; i < temperatures.size(); i++) {
        int distance = 1;
        bool is_warmer = false;
        for (int j = i + 1; j < temperatures.size(); j++) {
          if (temperatures[i] < temperatures[j]) {
            is_warmer = true;
            break;
          }
          distance++;
        }
        if (!is_warmer) {
          distance = 0;
        }
        distances.push_back(distance);
      }
      return distances;
    }
  };
