class Solution {
public:
  string alienOrder(vector<string>& words) {
    map<char, int> letter_to_cnt;
    for (string word : words) {
      for (char letter : word) {
        letter_to_cnt[letter] = 0;
      }
    }

    map<char, vector<char>> letter_to_adjacents;
    for (int i = 0; i < words.size() - 1; i++) {
      string word = words[i];
      string next_word = words[i + 1];
      // previous word has the common prefix
      if (word.size() > next_word.size() && word.substr(0, next_word.size()) == next_word) {
        return "";
      }
      for (int j = 0; j < min(word.size(), next_word.size()); j++) {
        if (word[j] != next_word[j]) {
          letter_to_adjacents[word[j]].push_back(next_word[j]);
          letter_to_cnt[next_word[j]]++;
          break;
        }
      }
    }

    string alien_orderd = "";
    queue<char> traversing_letters;
    for (auto [letter, cnt] : letter_to_cnt) {
      if (cnt == 0) {
        traversing_letters.push(letter);
      }
    }

    while (!traversing_letters.empty()) {
      char letter = traversing_letters.front();
      traversing_letters.pop();

      alien_orderd += letter;
      for (char next_letter : letter_to_adjacents[letter]) {
        letter_to_cnt[next_letter]--;
        if (letter_to_cnt[next_letter] == 0) {
          traversing_letters.push(next_letter);
        }
      }
    }

    if (alien_orderd.size() < letter_to_cnt.size()) {
      return "";
    }
    return alien_orderd;
  }
};
