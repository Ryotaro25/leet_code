class Solution {
public:
  int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    if (beginWord.empty() || endWord.empty() || wordList.empty()) {
      return 0;
    }

    set<string> word_list(wordList.begin(), wordList.end());
    set<string> is_used;
    is_used.insert(beginWord);

    queue<Transformation> word_and_cnt;
    word_and_cnt.emplace(beginWord, 1);
    while (!word_and_cnt.empty()) {
      auto [word, transformation_cnt] = word_and_cnt.front();
      word_and_cnt.pop();

      if (word == endWord) {
        return transformation_cnt;
      }

      for (int i = 0; i < word.size(); i++) {
        string next_word = word;
        for (char letter = 'a'; letter <= 'z'; letter++) {
          next_word[i] = letter;
          if (!word_list.contains(next_word)) {
            continue;
          }
          if (is_used.contains(next_word)) {
            continue;
          }
          is_used.insert(next_word);
          word_and_cnt.emplace(next_word, transformation_cnt + 1);
        }
      }
    }
    return 0;
  }

private:
  struct Transformation {
    string word;
    int cnt;
  };
};
