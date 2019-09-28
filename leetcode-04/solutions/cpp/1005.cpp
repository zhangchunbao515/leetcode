class Solution {
 public:
  int largestSumAfterKNegations(vector<int>& A, int K) {
    sort(A.begin(), A.end());

    for (int i = 0; i < A.size(); i++) {
      if (A[i] > 0 || K == 0) break;
      A[i] = -A[i];
      K--;
    }

    return accumulate(A.begin(), A.end(), 0) -
           (K % 2) * *min_element(A.begin(), A.end()) * 2;
  }
};