class MyLinkedList {
  public:
    MyLinkedList() {
      head = nullptr;
    }
    
    int get(int index) {
      ListNode* node = head;
      int i = 0;
      while (node && i < index) {
        node = node->next;
        i++;
      }
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
      if (index == 0) {
        ListNode* new_head = new ListNode(val);
        new_head->next = head;
        head = new_head;
        return;
      }

      ListNode* prev_node = head;
      int i = 0;
      while (prev_node && i < index - 1) {
        prev_node = prev_node->next;
        i++;
      }
      // LinkedListの長さよりindexの方が大きい場合
      if (!prev_node) {
        return;
      }
      ListNode* new_node = new ListNode(val);
      new_node->next = prev_node->next;
      prev_node->next = new_node;
    }
    
    void deleteAtIndex(int index) {
      if (index < 0 || head == nullptr) {
        return;
      }

      ListNode* target_node = head;
      int i = 0;
      while (target_node && i < index) {
        target_node = target_node->next;
        i++;
      }
      if (target_node == nullptr) {
        return;
      }
      ListNode* next_node = target_node->next;

      if (index == 0) {
        head = next_node;
        return;
      }

      ListNode* prev_node = head;
      int j = 0;
      while (prev_node && j < index - 1) {
        prev_node = prev_node->next;
        j++;
      }
      prev_node->next = next_node;
    }

  private:
    struct ListNode {
      int val;
      ListNode* next;
      ListNode(int x): val(x), next(nullptr) {}
    };

    ListNode* head;
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