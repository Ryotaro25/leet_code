class Solution {
  public:
    int evalRPN(vector<string>& tokens) {
      if (tokens.size() == 0) {
        return 0;
      }

      stack<int> nums;
      for (auto token : tokens) {
        if (token == "+" || token == "-" || token == "*" || token == "/") {
          int second_num = nums.top();
          nums.pop();
          int first_num = nums.top();
          nums.pop();

          int calculated = 0;
          if (token == "+") {
            calculated = first_num + second_num;
          } else if (token == "-") {
            calculated = first_num - second_num;
          } else if (token == "*") {
            calculated = first_num * second_num;
          } else if (token == "/") {
            calculated = first_num / second_num;
          }
          nums.push(calculated);
          continue;
        }
        nums.push(stoi(token));
      }
      return nums.top();
    }
  };
