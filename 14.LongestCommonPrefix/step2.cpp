class Solution {
public:
  string longestCommonPrefix(vector<string>& strs) {
    map<string_view, int> prefix_to_count;
    for (string_view str : strs) {
      for (int i = 1; i <= str.size(); i++) {
        prefix_to_count[str.substr(0, i)]++;
      }
    }

    string_view common_prefix = "";
    for (auto [prefix, cnt] : prefix_to_count) {
      if (cnt == strs.size()) {
        common_prefix = prefix;
      }
    }
    return static_cast<string>(common_prefix);
  }
};
