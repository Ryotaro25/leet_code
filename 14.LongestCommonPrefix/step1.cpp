class Solution {
public:
  string longestCommonPrefix(vector<string>& strs) {
    map<string, int> prefix_to_count;
    for (auto str : strs) {
      for (int i = 1; i <= str.size(); i++) {
        prefix_to_count[str.substr(0, i)]++;
      }
    }

    string common_prefix = "";
    for (auto [prefix, cnt] : prefix_to_count) {
      if (cnt == strs.size()) {
        common_prefix = prefix;
      }
    }
    return common_prefix;
  }
};
