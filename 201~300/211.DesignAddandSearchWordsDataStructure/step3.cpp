class WordDictionary {
public:
  WordDictionary() {
    root = new TrieNode();
  }
  
  void addWord(string word) {
    TrieNode* node = root;
    for (auto letter : word) {
      if (!node->letter_to_child.contains(letter)) {
        node->letter_to_child[letter] = new TrieNode();
      }
      node = node->letter_to_child[letter];
    }
    node->is_end = true;
  }
  
  bool search(string word) {
    return SearchWord(word, root);
  }

private:
  struct TrieNode {
    map<char, TrieNode*> letter_to_child;
    bool is_end;
  };

  TrieNode* root;

  bool SearchWord(string word, TrieNode* node) {
    for (int i = 0; i < word.size(); i++) {
      char current = word[i];
      if (!node->letter_to_child.contains(current)) {
        if (current != '.') {
          return false;
        }
        for (auto [letter, child] : node->letter_to_child) {
          if (SearchWord(word.substr(i + 1), child)) {
            return true;
          }
        }
        return false;
      }
      node = node->letter_to_child[current];
    }
    return node->is_end;
  }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */