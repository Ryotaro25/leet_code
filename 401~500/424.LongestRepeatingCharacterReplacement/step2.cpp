class Solution {
public:
  int characterReplacement(string s, int k) {
    int longest_length = 0;
    vector<int> letter_to_frequency(26, 0);
    int max_frequency = 0;

    int left = 0;
    for (int right = 0; right < s.size(); right++) {
      letter_to_frequency[s[right] - 'A']++;
      max_frequency = max(max_frequency, letter_to_frequency[s[right] - 'A']);

      // 必要な操作数 = 総文字数 - 最頻文字の数
      while (k < right - left + 1 - max_frequency) {
        letter_to_frequency[s[left] - 'A']--;
        left++;
      }
      longest_length = max(longest_length, right - left + 1);
    }
    return longest_length;
  }
};
