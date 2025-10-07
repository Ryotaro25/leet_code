class Solution {
public:
  string gcdOfStrings(string str1, string str2) {
    if (str1.size() > str2.size()) {
      swap(str1, str2);
    }

    for (int i = str1.size(); i >= 1; i--) {
      string divisor = str1.substr(0, i);
      if (ValidateDivisor(str1, str2, divisor)) {
        return divisor;
      }
    }

    return "";
  }

private:
  bool ValidateDivisor(const string& str1, const string& str2, const string& divisor) {
    string temp1;
    for (int i = 0; i < str1.size() / divisor.size(); i++) {
      temp1 += divisor;
    }
    if (temp1 != str1) {
      return false;
    }

    string temp2;
    for (int i = 0; i < str2.size() / divisor.size(); i++) {
      temp2 += divisor;
    }
    if (temp2 != str2) {
      return false;
    }

    return true;
  }
};
