class LRUCache {
public:
  LRUCache(int capacity) {
    this->capacity = capacity;
    dummy_head->next = dummy_tail;
    dummy_tail->prev = dummy_head;
  }
  
  int get(int key) {
    if (!key_to_node.contains(key)) {
      return -1;
    }
    Node* node = key_to_node[key];
    RemoveNode(node);
    AddBack(node);
    return node->val;
  }
  
  void put(int key, int value) {
    if (key_to_node.contains(key)) {
      Node* old_node = key_to_node[key];
      RemoveNode(old_node);
      delete old_node;
      key_to_node.erase(key);
    }

    Node* node = new Node(key, value);
    AddBack(node);
    key_to_node[key] = node;

    if (key_to_node.size() > capacity) {
      Node* real_head = dummy_head->next;
      key_to_node.erase(real_head->key);
      RemoveNode(real_head);
      delete real_head;
    }
  }

private:
  struct Node {
    int key;
    int val;
    Node* prev;
    Node* next;

    Node(int key, int val) : key(key), val(val), prev(nullptr), next(nullptr) {}
  };

  int capacity;
  Node* dummy_head = new Node(-1, -1);
  Node* dummy_tail = new Node(-1, -1);
  map<int, Node*> key_to_node;

  void AddBack(Node* node) {
    Node* real_tail = dummy_tail->prev;
    real_tail->next = node;
    node->prev = real_tail;
    node->next = dummy_tail;
    dummy_tail->prev = node;
  }

  void RemoveNode(Node* node) {
    Node* next_node = node->next;
    Node* prev_node = node->prev;

    next_node->prev = prev_node;
    prev_node->next = next_node;
  }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */