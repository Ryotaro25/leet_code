class Solution {
public:
  string reverseWords(string s) {
    string reversed = "";
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == ' ') {
        continue;
      }

      int start_index = i;
      while (i < s.size() && s[i] != ' ') {
        i++;
      }

      string word = s.substr(start_index, i - start_index);
      reverse(word.begin(), word.end());
      reversed += word;
      if (i != s.size()) {
        reversed += ' ';
      }
    }

    return reversed;
  }
};
