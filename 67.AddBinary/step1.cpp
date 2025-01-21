class Solution {
public:
  string addBinary(string a, string b) {
    int a_index = a.size() - 1;
    int b_index = b.size() - 1;
    char carry = '0';
    string sum = "";

    while (a_index >= 0 || b_index >= 0 || carry == '1') {
      char a_digit = '0';
      if (a_index >= 0) {
        a_digit = a[a_index];
        a_index--;
      }

      char b_digit = '0';
      if (b_index >= 0) {
        b_digit = b[b_index];
        b_index--;
      }

      if (a_digit == '1' && b_digit == '1') {
        sum = carry + sum;
        carry = '1';
      } else if ((a_digit == '1' && b_digit == '0') || (a_digit == '0' && b_digit == '1')) {
        if (carry == '1') {
          sum = '0' + sum;
          carry = '1';
        } else {
          sum = '1' + sum;
          carry = '0';
        }
      } else { 
        sum = carry + sum;
        carry = '0';
      }
    }
    return sum;
  }
};
