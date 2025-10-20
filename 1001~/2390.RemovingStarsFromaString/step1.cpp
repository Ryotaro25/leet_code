class Solution {
public:
  string removeStars(string s) {
    stack<char> reversed;
    for (char letter : s) {
      reversed.push(letter);
    }

    stack<char> removed;
    int remove_cnt = 0;
    while (!reversed.empty()) {
      char letter = reversed.top();
      reversed.pop();
      if (letter == '*') {
        remove_cnt++;
        continue;
      }
      if (remove_cnt > 0) {
        remove_cnt--;
        continue;
      }
      removed.push(letter);
    }


    string removed_str;
    while (!removed.empty()) {
      char letter = removed.top();
      removed.pop();
      removed_str += letter;
    }
    return removed_str;
  }
};
