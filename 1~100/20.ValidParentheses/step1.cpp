class Solution {
public:
  bool isValid(string s) {
    std::map<char, char> valid_pairs = {
      {'(', ')'},
      {'[', ']'},
      {'{', '}'},
    };

    std::stack<char> open_brackets;
    for (char bracket : s) {
      if (bracket == '(' || bracket == '[' || bracket == '{') {
        open_brackets.push(bracket);
        continue;
      }
      if (open_brackets.empty()) {
        return false;
      }
      if (bracket != valid_pairs[open_brackets.top()]) {
        return false;
      }
      open_brackets.pop();
    }
    return open_brackets.empty();
  }
};
