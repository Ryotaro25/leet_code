class TrieNode {
public:
  TrieNode() {
    for (int i = 0; i < 26; i++) {
      links[i] = nullptr;
    }
    is_end = false;
  }

  bool ContainsKey(char letter) {
    return links[letter - 'a'] != nullptr;
  }

  TrieNode* GetNode(char letter) {
    return links[letter - 'a'];
  }

  void PutLetter(char letter, TrieNode* node) {
    links[letter - 'a'] = node;
  }

  void SetEnd() {
    is_end = true;
  }

  bool IsEndWord() {
    return is_end;
  }

private:
  TrieNode* links[26];
  bool is_end;
};

class WordDictionary {
public:
  WordDictionary() {
    root = new TrieNode();
  }
  
  void addWord(string word) {
    TrieNode* node = root;
    for (char letter : word) {
      if (!node->ContainsKey(letter)) {
        node->PutLetter(letter, new TrieNode());
      }
      node = node->GetNode(letter);
    }
    node->SetEnd();
  }
  
  bool search(string word) {
    return SearchWord(word, 0, root);
  }

private:
  TrieNode* root;

  bool SearchWord(string& word, int index, TrieNode* node) {
    if (index == word.size()) {
      return node->IsEndWord();
    }

    char searching_letter = word[index];
    // wild card
    if (searching_letter == '.') {
      for (char letter = 'a'; letter <= 'z'; letter++) {
        TrieNode* next_node = node->GetNode(letter);
        if (!next_node) {
          continue;
        }
        if (SearchWord(word, index + 1, next_node)) {
          return true;
        }
      }
      return false;
    }

    if (node->ContainsKey(searching_letter)) {
      return SearchWord(word, index + 1, node->GetNode(searching_letter));
    }

    // there's no path
    return false;
  }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */