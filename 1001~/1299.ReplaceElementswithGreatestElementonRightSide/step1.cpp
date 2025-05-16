class Solution {
public:
  vector<int> replaceElements(vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++) {
      int max_val = 0;
      for (int j = i + 1; j < arr.size(); j++) {
        max_val = max(max_val, arr[j]);
      }
      arr[i] = max_val;

      if (i == arr.size() - 1) {
        arr[i] = -1;
      }
    }

    return arr;
  }
};
