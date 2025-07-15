class Solution {
public:
  bool exist(vector<vector<char>>& board, string word) {
    for (int row = 0; row < board.size(); row++) {
      for (int col = 0; col <  board[0].size(); col++) {
        if (board[row][col] != word[0]) {
          continue;
        }
        set<pair<int, int>> visited;
        int mattched_count = 0;
        CountMatchLetter(board, visited, mattched_count, row, col, word, 0);
        if (mattched_count == word.size()) {
          return true;
        }
      }
    }
    return false;
  }
  
private:
  void CountMatchLetter(vector<vector<char>>& board, set<pair<int, int>>& visited, int& cnt,
                        int row, int col, string word, int word_index) {
    visited.insert({row, col});
    cnt++;
    word_index++;

    vector<vector<int>> directions = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    for (auto direction : directions) {
      int next_row = row + direction[0];
      int next_col = col + direction[1];
      if (next_row < 0 || next_row >= board.size() || next_col < 0 || next_col >= board[0].size()) {
        continue;
      }
      if (visited.contains({next_row, next_col})) {
        continue;
      }
      if (word_index == word.size()) {
        continue;
      }
      if (board[next_row][next_col] != word[word_index]) {
        continue;
      }
      CountMatchLetter(board, visited, cnt, next_row, next_col, word, word_index);
    }
  }
};
