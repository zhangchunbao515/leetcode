class Solution {
 public:
  int maxTurbulenceSize(vector<int>& A) {
    int ans = 0;
    int count = 0;

    for (int i = 0; i + 1 < A.size(); i++) {
      if (A[i] > A[i + 1])
        count = count > 0 ? count + 1 : 1;
      else if (A[i] < A[i + 1])
        count = count < 0 ? count - 1 : -1;
      else
        count = 0;
      ans = max(ans, abs(count));
      count *= -1;
    }

    return ans + 1;
  }
};