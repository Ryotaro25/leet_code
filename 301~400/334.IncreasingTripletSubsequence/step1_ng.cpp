class Solution {
public:
  bool increasingTriplet(vector<int>& nums) {
    int first_val = nums[0];
    int second_val = UNDEFINED;
    int third_val = UNDEFINED;
    for (int num : nums) {
      if (num < first_val) {
        first_val = num;
        second_val = UNDEFINED;
        third_val = UNDEFINED;
      }
      if (num > first_val) {
        second_val = num;
      }
      if (num > third_val) {
        third_val = num;
      }
      cout << "fist: " << first_val << " second: " << second_val << " third: " << third_val << endl;

      if (second_val != UNDEFINED && third_val != UNDEFINED) {
        if (first_val < second_val && second_val < third_val) {
          return true;
        }
      }
    }

    return false;
  }

private:
  static constexpr int UNDEFINED = numeric_limits<int>::min();
};
