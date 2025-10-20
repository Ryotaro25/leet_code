class Solution {
public:
  string removeStars(string s) {
    stack<char> star_removed;
    for (char letter : s) {
      if (letter == '*') {
        star_removed.pop();
      } else {
        star_removed.push(letter);
      }
    }

    string removed_str;
    while (!star_removed.empty()) {
      removed_str += star_removed.top();
      star_removed.pop();
    }
    reverse(removed_str.begin(), removed_str.end());
    return removed_str;
  }
};
