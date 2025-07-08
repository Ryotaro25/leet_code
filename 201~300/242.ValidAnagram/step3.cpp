class Solution {
public:
  bool isAnagram(string s, string t) {
    if (s.size() != t.size()) {
      return false;
    }
    vector<int> letter_to_frequency(26);
    for (int i = 0; i < s.size(); i++) {
      letter_to_frequency[s[i] - 'a']++;
      letter_to_frequency[t[i] - 'a']--;
    }

    for (int num : letter_to_frequency) {
      if (num != 0) {
        return false;
      }
    }
    return true;
  }
};
