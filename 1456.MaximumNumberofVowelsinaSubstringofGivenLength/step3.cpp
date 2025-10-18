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
      num_vowels += vowels.count(s[i]);
    }

    int max_num_vowels = num_vowels;
    for (int i = k; i < s.size(); i++) {
      num_vowels += vowels.count(s[i]) - vowels.count(s[i - k]);
      max_num_vowels = max(max_num_vowels, num_vowels);
    }
    return max_num_vowels;
  }
};
