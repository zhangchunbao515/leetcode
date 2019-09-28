class Solution {
 public:
  int sumSubarrayMins(vector<int>& A) {
    const int n = A.size();
    const int kMod = 1e9 + 7;

    int ans = 0;
    vector<int> prev(n);
    vector<int> next(n);
    stack<int> stack1;
    stack<int> stack2;

    for (int i = 0; i < n; i++) {
      prev[i] = i + 1;
      next[i] = n - i;
    }

    for (int i = 0; i < n; i++) {
      while (!stack1.empty() && A[stack1.top()] > A[i]) stack1.pop();
      prev[i] = stack1.empty() ? i + 1 : i - stack1.top();
      stack1.push(i);

      while (!stack2.empty() && A[stack2.top()] > A[i]) {
        next[stack2.top()] = i - stack2.top();
        stack2.pop();
      }
      stack2.push(i);
    }

    for (int i = 0; i < n; i++) ans = (ans + A[i] * prev[i] * next[i]) % kMod;

    return ans;
  }
};