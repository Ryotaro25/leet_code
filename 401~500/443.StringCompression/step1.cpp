class Solution {
public:
  int compress(vector<char>& chars) {
    int i = 0;
    int compressed_length = 0;
    while (i < chars.size()) {
      int num_letters = 1;
      while (i + num_letters < chars.size() && chars[i + num_letters] == chars[i]) {
        num_letters++;
      }

      chars[compressed_length] = chars[i];
      compressed_length++;
      if (num_letters > 1) {
        for (char num : to_string(num_letters)) {
          chars[compressed_length] = num;
          compressed_length++;
        }
      }
      i += num_letters;
    }

    return compressed_length;
  }
};