class Solution {
public:
  vector<int> plusOne(vector<int>& digits) {
    int carry = 1;
    for (int i = digits.size() - 1; i >= 0; i--) {
      int digit = digits[i] + carry;
      if (digit >= 10) {x
        digit %= 10;
        carry = 1;
      } else {
        carry = 0;
      }

      digits[i] = digit;
    }

    if (carry) {
      digits.insert(digits.begin(), carry);
    }

    return digits;
  }
};
