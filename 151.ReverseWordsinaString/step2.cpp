class Solution {
public:
  string reverseWords(string s) {
    vector<string> words;
    for (int i = s.size() - 1; i >= 0; i--) {
      if (s[i] == ' ') {
        continue;
      }

      string word = "";
      while (i >= 0 && s[i] != ' ') {
        word += s[i];
        i--;
      }
      reverse(word.begin(), word.end());
      words.push_back(word);
    }

    string reversed_word = "";
    for (int i = 0; i < words.size(); i++) {
      reversed_word += words[i];
      if (i != words.size() - 1) {
        reversed_word += " ";
      }
    }
    return reversed_word;
  }
};
