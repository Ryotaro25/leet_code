class Solution {
public:
  int countSubstrings(string s) {
    int palindromic_cnt = 0;
    for (int i = 0; i < s.size(); i++) {
      palindromic_cnt += CountPalindrome(i, i, s);
      palindromic_cnt += CountPalindrome(i, i + 1, s);
    }
    return palindromic_cnt;
  }

private:
  int CountPalindrome(int left, int right, string& s) {
    int cnt = 0;
    while (left >= 0 && right < s.size()) {
      if (s[left] != s[right]) {
        break;
      }
      cnt++;
      left--;
      right++;
    }
    return cnt;
  }
};
