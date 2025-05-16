class Solution {
public:
  int shipWithinDays(vector<int>& weights, int days) {
    int left = 0;
    int right = 0;

    for (int i = 0; i < weights.size(); i++) {
      left = max(left, weights[i]);
      right += weights[i];
    }

    while (left < right) {
      int middle = left + (right - left) / 2;
      cout << middle << endl;
      
      if (IsLoadable(weights, middle, days)) {
        right = middle;
      } else {
        left = middle + 1;
      }
    }

    return left;
  }

private:
  bool IsLoadable(vector<int>& weights, int capacity, int required_days) {
    int day = 1;
    int total_weight = 0;
    for (auto weight : weights) {
      total_weight += weight;
      if (total_weight > capacity) {
        total_weight = weight;
        day++;
      }
      if (day > required_days) {
        return false;
      }
    }

    return true;
  }
};
