class Solution {
public:
  int strStr(string haystack, string needle) {
    int haystack_size = haystack.size();
    int needle_size = needle.size();
    for (int i = 0; i <= haystack_size - needle_size; i++) {
      for (int j = 0; j < needle_size; j++) {
        if (needle[j] != haystack[j + i]) {
          break;
        }
        if (j == needle_size - 1) {
          return i;
        }
      }
      return i;
    }

    return -1;
  }
};
