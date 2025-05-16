class Solution {
public:
  string reverseWords(string s) {
    vector<string> words;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == ' ') {
        continue;
      }
      int start = i;
      while (i < s.size() && s[i] != ' ') {
        i++;
      }

      string word = s.substr(start, i - start);
      words.push_back(word);
    }

    reverse(words.begin(), words.end());

    string reversed_word;
    for (int i = 0; i < words.size(); i++) {
      reversed_word += words[i];
      if (i != words.size() - 1) {
        reversed_word += " ";
      }
    }

    return reversed_word;
  }
};
