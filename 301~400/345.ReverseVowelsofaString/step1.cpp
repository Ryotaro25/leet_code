class Solution {
public:
  string reverseVowels(string s) {
    set<char> vowels = {'a', 'e', 'i', 'o', 'u'};

    string reversed = s;
    int left = 0;
    int right = s.size() - 1;
    while (left < right) {
      if (!vowels.contains(tolower(s[left]))) {
        left++;
      }
      if (!vowels.contains(tolower(s[right]))) {
        right--;
      }
      if (vowels.contains(tolower(s[left])) && vowels.contains(tolower(s[right]))) {
        swap(reversed[left], reversed[right]);
        left++;
        right--;
      }
    }

    return reversed;
  }
};
