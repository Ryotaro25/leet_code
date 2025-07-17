class Solution {
public:
  vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
    set<string> found_words;
    for (string word : words) {
      for (int row = 0; row < board.size(); row++) {
        for (int col = 0; col < board[0].size(); col++) {
          if (board[row][col] != word[0]) {
            continue;
          }
          vector<vector<char>> cloned_board = board;
          if (SearchWord(cloned_board, row, col, word, 0)) {
            found_words.insert(word);
          }
        }
      }
    }

    return vector<string>(found_words.begin(), found_words.end());
  }

private:
  bool SearchWord(vector<vector<char>>& board, int row, int col, string word, int word_index) {
    if (row < 0 || row >= board.size() || col < 0 || col >= board[0].size()) {
      return false;
    }
    if (board[row][col] == '@') {
      return false;
    }
    if (board[row][col] != word[word_index]) {
      return false;
    }
    if (word_index == word.size() - 1) {
      return true;
    }
    char temp = board[row][col];
    board[row][col] = '@';
    int row_directions[4] = {-1, 0, 1, 0};
    int col_directions[4] = {0, 1, 0, -1};
    for (int i = 0; i < 4; i++) {
      int next_row = row + row_directions[i];
      int next_col = col + col_directions[i];
      if (SearchWord(board, next_row, next_col, word, word_index + 1)) {
        return true;
      }
    }
    board[row][col] = temp;
    return false;
  }
};
