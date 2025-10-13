class Solution {
public:
  int compress(vector<char>& chars) {
    int i = 0;
    int num_compressed = 0;
    while (i < chars.size()) {
      int num_same_letters = 1;
      while (i + num_same_letters < chars.size() && chars[i + num_same_letters] == chars[i]) {
        num_same_letters++;
      }
      chars[num_compressed] = chars[i];
      num_compressed++;
      if (num_same_letters > 1) {
        for (char letter : to_string(num_same_letters)) {
          chars[num_compressed] = letter;
          num_compressed++;
        }
      }
      i += num_same_letters;
    }

    return num_compressed;
  }
};
