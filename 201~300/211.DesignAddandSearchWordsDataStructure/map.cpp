class WordDictionary {
public:
  WordDictionary() {
    root = new TrieNode();
  }

  void addWord(string word) {
    TrieNode* node = root;
    for (char letter : word) {
      if (!node->letter_to_children.contains(letter)) {
        node->letter_to_children[letter] = new TrieNode();
      }
      node = node->letter_to_children[letter];
    }
    node->is_end = true;
  }

  bool search(string word) {
    return SearchNode(word, root);
  }

private:
  struct TrieNode {
    map<char, TrieNode*> letter_to_children;
    bool is_end = false;
  };

  TrieNode* root;

  bool SearchNode(string word, TrieNode* node) {
    for (int i = 0; i < word.size(); i++) {
      char searching_letter = word[i];
      if (!node->letter_to_children.contains(searching_letter)) {
        // wild card
        if (searching_letter == '.') {
          for (auto [letter, child_node] : node->letter_to_children) {
            if (SearchNode(word.substr(i + 1), child_node)) {
              return true;
            }
          }
        }
        return false;
      }
      node = node->letter_to_children[searching_letter];
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
