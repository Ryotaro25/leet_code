class Solution {
public:
  string alienOrder(vector<string>& words) {
    map<char, int> letter_in_degree;
    for (string word : words) {
      for (char letter : word) {
        letter_in_degree[letter] = 0;
      }
    }

    map<char, vector<char>> letter_to_adjacents;
    for (int i = 0; i < words.size() - 1; i++) {
      string word = words[i];
      string next_word = words[i + 1];

      if (word.size() > next_word.size() && word.substr(0, next_word.size()) == next_word) {
        return "";
      }

      for (int j = 0; j < min(word.size(), next_word.size()); j++) {
        if (word[j] == next_word[j]) {
          continue;
        }
        letter_in_degree[next_word[j]]++;
        letter_to_adjacents[word[j]].push_back(next_word[j]);
        break;
      }
    }

    queue<char> traversing_letters;
    for (auto [letter, degree] : letter_in_degree) {
      if (degree == 0) {
        traversing_letters.push(letter);
      }
    }

    string aliend_ordered;
    while (!traversing_letters.empty()) {
      char current_letter = traversing_letters.front();
      traversing_letters.pop();

      aliend_ordered += current_letter;
      for (char next_letter : letter_to_adjacents[current_letter]) {
        letter_in_degree[next_letter]--;
        if (letter_in_degree[next_letter] == 0) {
          traversing_letters.push(next_letter);
        }
      }
    }

    if (aliend_ordered.size() < letter_in_degree.size()) {
      return "";
    }
    return aliend_ordered;
  }
};
