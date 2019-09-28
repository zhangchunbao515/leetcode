class Solution {
 public:
  int maxWidthRamp(vector<int>& A) {
    const int n = A.size();

    int ans = 0;
    stack<int> stack;

    for (int i = 0; i < n; i++)
      if (stack.empty() || A[i] < A[stack.top()]) stack.push(i);

    for (int j = n - 1; j > ans; j--)
      while (!stack.empty() && A[stack.top()] <= A[j]) {
        ans = max(ans, j - stack.top());
        stack.pop();
      }

    return ans;
  }
};