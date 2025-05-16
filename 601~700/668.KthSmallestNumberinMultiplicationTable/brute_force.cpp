class Solution {
// TLE
public:
  int findKthNumber(int m, int n, int k) {
   vector<int> multiplied_nums;
   for (int i = 1; i <= m; i++) {
     for (int j = 1; j <= n; j++) {
      multiplied_nums.push_back(i * j);
     }
   }
   sort(multiplied_nums.begin(), multiplied_nums.end());
   return multiplied_nums[k - 1];
  }
};
