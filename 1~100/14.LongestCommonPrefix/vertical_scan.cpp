class Solution {
public:
  string longestCommonPrefix(vector<string>& strs) {
    if (strs.size() == 0) {
      return "";
    }
    string first_str = strs[0];
    for (int i = 0; i < first_str.size(); i++) {
      char letter = first_str[i];
      for (int j = 1; j < strs.size(); j++) {
        if (i != strs[j].size() && strs[j][i] == letter) {
          continue;
        }
        return first_str.substr(0, i);
      }
    }
    return first_str;
  }
};
