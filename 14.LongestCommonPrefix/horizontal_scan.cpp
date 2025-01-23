class Solution {
public:
  string longestCommonPrefix(vector<string>& strs) {
    if (strs.size() == 0) {
      return "";
    }

    string prefix = strs[0];
    for (int i = 1; i < strs.size(); i++) {
      // 先頭にいるかどうかをみたいのでcontainsでは動作しない
      while (strs[i].find(prefix) != 0) {
        // 一文字ずつ削る
        prefix = prefix.substr(0, prefix.size() - 1);
        cout << prefix << endl;
        if (prefix.empty()) {
          return "";
        }
      }
    }

    return prefix;
  }
};
