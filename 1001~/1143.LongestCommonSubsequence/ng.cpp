class Solution {
public:
  int longestCommonSubsequence(string text1, string text2) {
    string text_for_map = text1;
    string text_for_iterate = text2;
    if (text2.size() > text1.size()) {
      swap(text_for_map, text_for_iterate);
    }

    map<char, int> letter_to_frequencey;
    for (char letter : text_for_map) {
      letter_to_frequencey[letter]++;
    }
    int longest_length = 0;
    for (char letter : text_for_iterate) {
      if (!letter_to_frequencey.contains(letter)) {
        continue;
      }
      longest_length++;
      letter_to_frequencey[letter]--;
    }
    return longest_length;
  }
};
