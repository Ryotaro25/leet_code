class Solution {
public:
  int maxOperations(vector<int>& nums, int k) {
    int num_operations = 0;
    set<int> visited;
    for (int i = 0; i < nums.size(); i++) {
      if (visited.contains(i)) {
        continue;
      }
      int compliment = k - nums[i];
      for (int j = i + 1; j < nums.size(); j++) {
        if (visited.contains(j)) {
          continue;
        }
        if (nums[j] == compliment) {
          num_operations++;
          visited.insert(j);
          break;
        }
      }
    }

    return num_operations;
  }
};
