class MyStack {
public:
  MyStack() {
    is_first_as_input = true;
  }
  
  void push(int x) {
    if (is_first_as_input) {
      first_nums.push(x);
    } else {
      second_nums.push(x);
    }
  }
  
  int pop() {
    int top_num = top();
    if (is_first_as_input) {
      first_nums.pop();
    } else {
      second_nums.pop();
    }
    is_first_as_input = !is_first_as_input;
    return top_num;
  }
  
  int top() {
    int top_element = -1;
    if (empty()) {
      return top_element;
    }
    if (is_first_as_input) {
      while (first_nums.size() > 1) {
        second_nums.push(first_nums.front());
        first_nums.pop();
      }
      top_element = first_nums.front();
    } else {
      while (second_nums.size() > 1) {
        first_nums.push(second_nums.front());
        second_nums.pop();
      }
      top_element = second_nums.front();
    }
    return top_element;
  }
  
  bool empty() {
    return first_nums.empty() && second_nums.empty();
  }

private:
  queue<int> first_nums;
  queue<int> second_nums;
  bool is_first_as_input;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
