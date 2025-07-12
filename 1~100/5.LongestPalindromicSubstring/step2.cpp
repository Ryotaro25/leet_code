class Solution {
public:
  string longestPalindrome(string s) {
    string longest_palindrome = "";
    for (int i = 0; i < s.size(); i++) {
      // aba
      string candidate = Expand(i, i, s);
      if (candidate.size() > longest_palindrome.size()) {
        longest_palindrome = candidate;
      }

      // abba
      candidate = Expand(i, i + 1, s);
      if (candidate.size() > longest_palindrome.size()) {
        longest_palindrome = candidate;
      }
    } 

    return longest_palindrome;
  }

private:
  string Expand(int left, int right, string& s) {
    while (left >= 0 && right < s.size()) {
      if (s[left] != s[right]) {
        break;
      }
      left--;
      right++;
    }

    // 終了インデックス - 開始インデックス + 1
    // (right−1)−(left+1)+1
    return s.substr(left + 1, right - left - 1);
  }
};