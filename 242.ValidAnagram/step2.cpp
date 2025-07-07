class Solution {
public:
  bool isAnagram(string s, string t) {
    if (s.size() != t.size()) {
      return false;
    }
    map<char, int> letter_to_frequency;
    for (int i = 0; i < s.size(); i++) {
      letter_to_frequency[s[i]]++;
      letter_to_frequency[t[i]]--;
    }

    for (auto [letter, frequency] : letter_to_frequency) {
      if (frequency != 0) {
        return false;
      }
    }
    return true;
  }
};
