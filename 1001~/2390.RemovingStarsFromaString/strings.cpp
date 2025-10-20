class Solution {
public:
  string removeStars(string s) {
    string star_removed_str;
    for (char letter : s) {
      if (letter == '*') {
        star_removed_str.pop_back();
      } else {
        star_removed_str.push_back(letter);
      }
    }

    return star_removed_str;
  }
};
