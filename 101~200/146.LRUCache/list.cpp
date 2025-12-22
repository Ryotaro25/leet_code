class LRUCache {
public:
    LRUCache(int capacity) {
      this->capacity = capacity;
    }
    
    int get(int key) {
      auto it = key_to_node.find(key);
      if (it == key_to_node.end()) {
        return -1;
      }

      int value = it->second->second;
      lru.erase(it->second);
      lru.push_front({key, value});

      key_to_node.erase(it);
      key_to_node[key] = lru.begin();
      return value;
    }
    
    void put(int key, int value) {
      auto it = key_to_node.find(key);
      if (it != key_to_node.end()) {
        lru.erase(it->second);
        key_to_node.erase(it);
      }

      lru.push_front({key, value});
      key_to_node[key] = lru.begin();

      if (key_to_node.size() > capacity) {
        auto it = key_to_node.find(lru.rbegin()->first);
        key_to_node.erase(it);
        lru.pop_back();
      }
    }

private:
  int capacity;
  map<int, list<pair<int, int>>::iterator> key_to_node;
  list<pair<int, int>> lru;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
