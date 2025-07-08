class Solution {
public:
  bool isPalindrome(string s) {
    string from_forward = "";
    for (char letter : s) {
      if (isdigit(letter)) {
        from_forward += letter;
      }
      if (isalpha(letter)) {
        from_forward += tolower(letter);
      }
    }

    string from_back = "";
    for (int i = s.size() - 1; i >= 0; i--) {
      if (isdigit(s[i])) {
        from_back += s[i];
      }
      if (isalpha(s[i])) {
        from_back += tolower(s[i]);
      }
    }
    return from_forward == from_back;
  }
};
