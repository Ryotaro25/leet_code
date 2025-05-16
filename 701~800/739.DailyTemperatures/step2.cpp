class Solution {
  public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
      vector<int> distances(temperatures.size(), 0);
      stack<int> prev_indexes;
      for (int i = 0; i < temperatures.size(); i++) {
        while (!prev_indexes.empty()) {
          if (temperatures[i] <= temperatures[prev_indexes.top()]) {
            break;
          }
          int prev_index = prev_indexes.top();
          prev_indexes.pop();
          distances[prev_index] = i - prev_index;
        }
        prev_indexes.push(i);
      }
      return distances;
    }
  };
