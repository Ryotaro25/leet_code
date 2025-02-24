class MyLinkedList {
  public:
    MyLinkedList() {
      head = nullptr;
    }
    
    int get(int index) {
      ListNode* node = GetNode(index);
      if (!node) {
        return -1;
      }
      return node->val;
    }

    void addAtHead(int val) {
      ListNode* new_head = new ListNode(val);
      new_head->next = head;
      head = new_head;
    }
    
    void addAtTail(int val) {
      ListNode* new_tail = new ListNode(val);
      if (head == nullptr) {
        head = new_tail;
        return;
      }

      ListNode* node = head;
      while (node && node->next) {
        node = node->next;
      }
      node->next = new_tail;
    }
    
    void addAtIndex(int index, int val) {
      ListNode* new_node = new ListNode(val);
      if (index == 0) {
        new_node->next = head;
        head = new_node;
        return;
      }

      ListNode* prev_node = GetNode(index - 1);
      // LinkedListの長さよりindexの方が大きい場合
      if (!prev_node) {
        return;
      }
      new_node->next = prev_node->next;
      prev_node->next = new_node;
    }
    
    void deleteAtIndex(int index) {
      if (index < 0 || head == nullptr) {
        return;
      }

      ListNode* target_node = GetNode(index);
      if (target_node == nullptr) {
        return;
      }

      ListNode* next_node = target_node->next;
      if (index == 0) {
        head = next_node;
        return;
      }

      ListNode* prev_node = GetNode(index - 1);
      prev_node->next = next_node;
    }

  private:
    struct ListNode {
      int val;
      ListNode* next;
      ListNode(int x): val(x), next(nullptr) {}
    };

    ListNode* head;

    ListNode* GetNode(int index) {
      ListNode* node = head;
      int i = 0;
      while (node && i < index) {
        node = node->next;
        i++;
      }
      if (!node) {
        return nullptr;
      }
      return node;
    }
  };
  
  /**
   * Your MyLinkedList object will be instantiated and called as such:
   * MyLinkedList* obj = new MyLinkedList();
   * int param_1 = obj->get(index);
   * obj->addAtHead(val);
   * obj->addAtTail(val);
   * obj->addAtIndex(index,val);
   * obj->deleteAtIndex(index);
   */