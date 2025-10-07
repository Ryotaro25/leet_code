class Solution {
public:
  string mergeAlternately(string word1, string word2) {
    if (word1.empty() && word2.empty()) {
      return "";
    }

    string merged_word;
    int i = 0;
    int j = 0;
    while (i < word1.size() || j < word2.size()) {
      if (i < word1.size()) {
        merged_word.push_back(word1[i]);
        i++;
      }
      if (j < word2.size()) {
        merged_word.push_back(word2[j]);
        j++;
      }
    }

    return merged_word;
  }
};
