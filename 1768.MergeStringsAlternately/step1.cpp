class Solution {
public:
  string mergeAlternately(string word1, string word2) {
    string merged_word;
    bool is_first = true;

    int i = 0;
    int j = 0;
    while (i < word1.size() && j < word2.size()) {
      if (is_first) {
        merged_word.push_back(word1[i]);
        i++;
      } else {
        merged_word.push_back(word2[j]);
        j++;
      }
      is_first = !is_first;
    }

    while (i < word1.size()) {
      merged_word.push_back(word1[i]);
      i++;
    }
    while (j < word2.size()) {
      merged_word.push_back(word2[j]);
      j++;
    }
    return merged_word;
  }
};
