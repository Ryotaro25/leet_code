// https://leetcode.com/problems/implement-trie-prefix-tree/
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

  TrieNode* Get(char letter) {
    return links[letter - 'a'];
  }

  void Put(char letter, TrieNode* node) {
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

class Trie {
public:
  Trie() {
    root = new TrieNode();
  }

  ~Trie() {
    delete root;
  }
  
  void insert(string word) {
    TrieNode* node = root;
    for (int i = 0; i < word.size(); i++) {
      char letter = word[i];
      if (!node->ContainsKey(letter)) {
        node->Put(letter, new TrieNode());
      }
      node = node->Get(letter);
    }
    node->SetEnd();
  }

  bool search(string word) {
    TrieNode* node = SearchPrefix(word);
    return node && node->IsEndWord();
  }
  
  TrieNode* SearchPrefix(const string& word) {
    TrieNode* node = root;
    for (int i = 0; i < word.size(); i++) {
      char letter = word[i];
      if (node->ContainsKey(letter)) {
        node = node->Get(letter);
      } else {
        return nullptr;
      }
    }
    return node;
  }
  
  bool startsWith(string prefix) {
    TrieNode* node = SearchPrefix(prefix);
    return node != nullptr;
  }

private:
  TrieNode* root;
};




/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */