class Solution {
public:
  bool increasingTriplet(vector<int>& nums) {
    int first_val = UNDEFINED;
    int second_val = UNDEFINED;
    int third_val = UNDEFINED;

    for (int num : nums) {
      if (num <= first_val) {
        first_val = num;
      } else if (num <= second_val) {
        second_val = num;
      } else {
        return true;
      }
    }

    return false;
  }

private:
  static constexpr int UNDEFINED = numeric_limits<int>::max();
};
