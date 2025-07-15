// TLE
class Solution {
public:
  bool exist(vector<vector<char>>& board, string word) {
    for (int row = 0; row < board.size(); row++) {
      for (int col = 0; col <  board[0].size(); col++) {
        if (board[row][col] != word[0]) {
          continue;
        }
        set<pair<int, int>> visited;
        if (IsWordExist(board, visited, row, col, word, 0)) {
          return true;
        }
      }
    }
    return false;
  }
  
private:
  bool IsWordExist(vector<vector<char>>& board, set<pair<int, int>>& visited,
                        int row, int col, string& word, int word_index) {
    if (row < 0 || row >= board.size() || col < 0 || col >= board[0].size()) {
      return false;
    }
    if (visited.contains({row, col})) {
      return false;
    }
    if (board[row][col] != word[word_index]) {
      return false;
    }
    if (word_index == word.size() - 1) {
      return true;
    }

    visited.insert({row, col});
    vector<vector<int>> directions = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    for (auto direction : directions) {
      int next_row = row + direction[0];
      int next_col = col + direction[1];
      
      if (IsWordExist(board, visited, next_row, next_col, word, word_index + 1)) {
        return true;
      }
    }
    visited.erase({row, col});
    return false;
  }
};
