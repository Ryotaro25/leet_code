class MinStack {
  public:
    MinStack() {
      min_num = std::numeric_limits<int>::max();
    }
    
    void push(int val) {
      my_stack.push_back(val);
      if (min_stack.empty()) {
        min_stack.push_back(val);
        return;
      }
      min_num = min(min_stack.back(), val);
      min_stack.push_back(min_num);
    }
    
    void pop() {
      my_stack.pop_back();
      min_stack.pop_back();
    }
    
    int top() {
      return my_stack.back();
    }
    
    int getMin() {
      return min_stack.back();
    }

  private:
    vector<int> my_stack;
    vector<int> min_stack;
    int min_num;
  };
  
  /**
   * Your MinStack object will be instantiated and called as such:
   * MinStack* obj = new MinStack();
   * obj->push(val);
   * obj->pop();
   * int param_3 = obj->top();
   * int param_4 = obj->getMin();
   */
 