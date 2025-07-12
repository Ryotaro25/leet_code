class Solution {
public:
  string longestPalindrome(string s) {
    string longest_palindrome = "";
    for (int i = 0; i < s.size(); i++) {
      for (int j = i; j < s.size(); j++) {
        string sub_string = s.substr(i, j - i + 1);
        if (!IsPalindrome(sub_string)) {
          continue;
        }
        if (longest_palindrome.size() > sub_string.size()) {
          continue;
        }
        longest_palindrome = sub_string;
      }
    }
    return longest_palindrome;
  }

private:
  bool IsPalindrome(string s) {
    int left = 0;
    int right = s.size() - 1;
    while (left < right) {
      if (s[left] != s[right]) {
        return false;
      }
      left++;
      right--;
    }

    return true;
  }
};
