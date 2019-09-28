class Solution {
 public:
  int evalRPN(vector<string>& tokens) {
    stack<int> stack;
    int a;
    int b;

    for (string& token : tokens) {
      if (token == "+") {
        helper(stack, a, b);
        stack.push(a + b);
      } else if (token == "-") {
        helper(stack, a, b);
        stack.push(a - b);
      } else if (token == "*") {
        helper(stack, a, b);
        stack.push(a * b);
      } else if (token == "/") {
        helper(stack, a, b);
        stack.push(a / b);
      } else {
        stack.push(stoi(token));
      }
    }

    return stack.top();
  }

 private:
  void helper(stack<int>& stack, int& a, int& b) {
    b = stack.top();
    stack.pop();
    a = stack.top();
    stack.pop();
  }
};