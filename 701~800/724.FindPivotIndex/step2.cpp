// cumulative NG
// [-1,-1,0,0,-1,-1]
// output 3
// expexted 2
class Solution {
public:
  int pivotIndex(vector<int>& nums) {
    map<int, int> pivot_to_sum;
    pivot_to_sum[0] = 0;
    for (int i = 0; i < nums.size(); i++) {
      pivot_to_sum[i + 1] = pivot_to_sum[i] + nums[i];
    }

    int right_sum = 0;
    for (int i = nums.size() - 1; i >= 0; i--) {
      cout << pivot_to_sum[i] << endl;
      if (pivot_to_sum[i] == right_sum) {
        return i;
      }
      right_sum += nums[i];
    }
    
    return NOANSWER;
  }

private:
  static constexpr int NOANSWER = -1;
};
