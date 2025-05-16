class Solution {
  public:
    int findMin(vector<int>& nums) {
      set<int> unique_nums_set(nums.begin(), nums.end());
      vector<int> unique_nums;
      for (int num : unique_nums_set) {
        unique_nums.push_back(num);
      }

      int left = 0;
      int right = unique_nums.size() - 1;

      while (left < right) {
        int middle = left + (right - left) / 2;

        if (unique_nums[middle] > unique_nums[right]) {
          left = middle + 1;
        } else {
          right = left;
        }
      }

      return unique_nums[left];
    }
  };
