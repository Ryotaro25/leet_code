class Solution {
public:
  bool checkIfExist(vector<int>& arr) {
    set<int> is_seen;
    for (auto num : arr) {
      if (is_seen.contains(num * 2) || (num % 2 == 0 && is_seen.contains(num / 2))) {
        return true;
      }
      is_seen.insert(num);
    }

    return false;
  }
};
