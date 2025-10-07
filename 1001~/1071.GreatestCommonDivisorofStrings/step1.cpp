class Solution {
public:
  string gcdOfStrings(string str1, string str2) {
    
    if (str1.size() > str2.size()) {
      swap(str1, str2);
    }
    string greatest_divisor;
    for (int i = 0; i < str1.size(); i++) {
      string divisor = str1.substr(0, i + 1);
      if (ValidateDivisor(str1, str2, divisor)) {
        greatest_divisor = divisor;
      }
    }
    return greatest_divisor;
  }

private:
  bool ValidateDivisor(string str1, string str2, string divisor) {
    // 2. str1がdivisorを繰り返して構成されているかチェック
    int num1 = str1.size() / divisor.size();
    string temp1 = "";
    for (int i = 0; i < num1; i++) {
      temp1 += divisor;
    }
    if (temp1 != str1) {
      return false;
    }
    
    // 3. str2がdivisorを繰り返して構成されているかチェック
    int num2 = str2.size() / divisor.size();
    string temp2 = "";
    for (int i = 0; i < num2; i++) {
      temp2 += divisor;
    }
    if (temp2 != str2) {
      return false;
    }
 
    return true;
  }
};
