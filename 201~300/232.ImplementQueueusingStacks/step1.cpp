class MyQueue {
public:
  MyQueue() {
    
  }
  
  void push(int x) {
    input_nums.push(x);
  }
  
  int pop() {
    if (reversed.empty()) {
      while (!input_nums.empty()) {
        reversed.push(input_nums.top());
        input_nums.pop();
      }
    }
    int top_num = reversed.top();
    reversed.pop();
    return top_num;
  }
  
  int peek() {
    if (reversed.empty()) {
      while (!input_nums.empty()) {
        reversed.push(input_nums.top());
        input_nums.pop();
      }
    }
    return reversed.top();
  }
  
  bool empty() {
    return input_nums.empty() && reversed.empty();
  }

private:
  stack<int> input_nums;
  stack<int> reversed;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */