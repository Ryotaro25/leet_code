class Solution {
public:
  int maxVowels(string s, int k) {
    if (s.empty() || k == 0) {
      return 0;
    }

    set<char> vowels = {
      'a', 'e', 'i', 'o', 'u'
    };
    int num_vowels = 0;
    for (int i = 0; i < k; i++) {
      if (vowels.contains(s[i])) {
        num_vowels++;
      }
    }

    int max_num_vowels = num_vowels;
    for (int i = k; i < s.size(); i++) {
      if (vowels.contains(s[i - k])) {
        num_vowels--;
      }
      if (vowels.contains(s[i])) {
        num_vowels++;
      }
      max_num_vowels = max(max_num_vowels, num_vowels);
    }
    return max_num_vowels;
  }
};
