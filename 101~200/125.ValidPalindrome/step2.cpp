class Solution {
public:
  bool isPalindrome(string s) {
    int left = 0;
    int right = s.size() - 1;

    while (left <= right) {
      if (!isdigit(s[left]) && !isalpha(s[left])) {
        left++;
        continue;
      }
      if (!isdigit(s[right]) && !isalpha(s[right])) {
        right--;
        continue;
      }
      if (tolower(s[left]) != tolower(s[right])) {
        return false;
      }
      left++;
      right--;
    }

    return true;
  }
};
