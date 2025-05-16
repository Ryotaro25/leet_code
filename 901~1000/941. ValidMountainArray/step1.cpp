class Solution {
public:
  bool validMountainArray(vector<int>& arr) {
    if (arr.size() < 3) {
      return false;
    }

    int max_index = 0;
    int max_val = numeric_limits<int>::min();
    for (int i = 0; i < arr.size(); i++) {
      if (arr[i] > max_val) {
        max_val = arr[i];
        max_index = i;
      }
    }

    if (max_index == 0 || max_index == arr.size() - 1) {
      return false;
    }

    for (int i = 0; i < max_index; i++) {
      if (arr[i] >= arr[i + 1]) {
        return false;
      }
    }

    for (int i = max_index; i < arr.size() - 1; i++) {
      if (arr[i] <= arr[i + 1]) {
        return false;
      }
    }

    return true;
  }
};
