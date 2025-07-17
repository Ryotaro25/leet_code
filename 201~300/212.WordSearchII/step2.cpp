class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
      if (board.empty() || board[0].empty() || words.empty()) {
        return {};
      }

      TrieNode* root = new TrieNode();
      for (const string& word : words) {
        TrieNode* node = root;
        for (char letter : word) {
          if (!node->letter_to_child.contains(letter)) {
            node->letter_to_child[letter] = new TrieNode();
          }
          node = node->letter_to_child[letter];
        }
        node->word = word;
      }

      vector<string> found_words;
      for (int row = 0; row < board.size(); row++) {
        for (int col = 0; col < board[0].size(); col++) {
          if (root->letter_to_child.contains(board[row][col])) {
            SearchWords(board, row, col, root, found_words);
          }
        }
      }
      return found_words;
    }

private:
  struct TrieNode {
    map<char, TrieNode*> letter_to_child;
    string word = "";
  };

  void SearchWords(vector<vector<char>>& board, int row, int col,
                   TrieNode* node, vector<string>& found_words) {
    if (row < 0 || row >= board.size() || col < 0 || col >= board[0].size()) {
      return;
    }
    if (board[row][col] == '@') {
      return;
    }
    if (!node->letter_to_child.contains(board[row][col])) {
      return;
    }

    char current_letter = board[row][col];
    TrieNode* child = node->letter_to_child[current_letter];
    if (child->word != "") {
      found_words.emplace_back(child->word);
      child->word = "";
    }

    board[row][col] = '@';
    int row_directions[4] = {-1, 0, 1, 0};
    int col_directions[4] = {0, 1, 0, -1};
    for (int i = 0; i < 4; i++) {
      int next_row = row + row_directions[i];
      int next_col = col + col_directions[i];
      SearchWords(board, next_row, next_col, child, found_words);
    }
    board[row][col] = current_letter;
  }
};
