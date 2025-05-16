class Solution {
public:
  int strStr(string haystack, string needle) {
    for (int i = 0; i < haystack.size(); i++) {
      if (haystack.size() - i < needle.size()) {
        break;
      }
      if (haystack[i] != needle[0]) {
        continue;
      }
      bool is_part = true;
      int index = i;
      for (int j = 0; j < needle.size() && index < haystack.size(); j++) {
        if (haystack[index] != needle[j]) {
          is_part = false;
        }
        index++;
      }

      if (is_part) {
        return i;
      }
    }

    return -1;
  }
};
