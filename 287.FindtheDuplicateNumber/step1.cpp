class Solution {
  public:
    int findDuplicate(vector<int>& nums) {
      int left = 1;
      int right = nums.size();

      int duplicate_num = -1;
      // 重複が存在する場合があるため
      while (left <= right) {
        int middle = left + (right - left) / 2;

        if (CountSmallOrEqualNum(nums, middle) <= middle) {
          left = middle + 1;
        } else {
          duplicate_num = middle;
          right = middle - 1;
        }
      }
      return duplicate_num;
    }

  private:
    int CountSmallOrEqualNum(vector<int>& nums, int target) {
      int cnt = 0;
      for (int num : nums) {
        if (num <= target) {
          cnt++;
        }
      }
      return cnt;
    }
  };
