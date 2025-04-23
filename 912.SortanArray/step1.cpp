class Solution {
  public:
    vector<int> sortArray(vector<int>& nums) {
      vector<int> sorted_nums = nums;
      MergeSort(sorted_nums, 0, sorted_nums.size() - 1);
      return sorted_nums;
    }

  private:
    void MergeSort(vector<int>& nums, int left, int right) {
      if (left >= right) {
        return;
      }
      int middle = left + (right - left) / 2;
      MergeSort(nums, left, middle);
      MergeSort(nums, middle + 1, right);
      Merge(nums, left, middle, right);
    }

    void Merge(vector<int>& nums, int left, int middle, int right) {
      int left_length = middle - left + 1; // middleも含める
      vector<int> left_nums(left_length);
      for (int i = 0; i < left_length; i++) {
        left_nums[i] = nums[left + i];
      }

      int right_length = right - middle; // middleは含めない
      vector<int> right_nums(right_length);
      for (int i = 0; i < right_length; i++) {
        right_nums[i] = nums[middle + 1 + i];
      }

      int left_idx = 0;
      int right_idx = 0;
      int merged_idx = left;
      while (left_idx < left_length && right_idx < right_length) {
        if (left_nums[left_idx] <= right_nums[right_idx]) {
          nums[merged_idx] = left_nums[left_idx];
          left_idx++;
        } else {
          nums[merged_idx] = right_nums[right_idx];
          right_idx++;
        }
        merged_idx++;
      }

      while (left_idx < left_length) {
        nums[merged_idx] = left_nums[left_idx];
        left_idx++;
        merged_idx++;
      }

      while (right_idx < right_length) {
        nums[merged_idx] = right_nums[right_idx];
        right_idx++;
        merged_idx++;
      }
    }
  };
