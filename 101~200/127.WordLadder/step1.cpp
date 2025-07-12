class Solution {
public:
  int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    if (beginWord.empty() || endWord.empty() || wordList.empty()) {
      return 0;
    }

    set<string> word_list(wordList.begin(), wordList.end());
    set<string> is_used;
    is_used.insert(beginWord);
    int num_words = UNREACHABLE;

    queue<Transformation> word_and_cnt;
    word_and_cnt.push({beginWord, 1});
    while (!word_and_cnt.empty()) {
      auto [word, transformation_cnt] = word_and_cnt.front();
      word_and_cnt.pop();

      if (word == endWord) {
        num_words = min(num_words, transformation_cnt);
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
          word_and_cnt.push({next_word, transformation_cnt + 1});
        }
      }
    }
    if (num_words == UNREACHABLE) {
      return 0;
    }
    return num_words;
  }

private:
  static constexpr int UNREACHABLE = numeric_limits<int>::max();
  struct Transformation {
    string word;
    int cnt;
  };
};
