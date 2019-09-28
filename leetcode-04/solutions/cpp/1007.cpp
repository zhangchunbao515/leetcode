class Solution {
 public:
  int minDominoRotations(vector<int>& A, vector<int>& B) {
    const int n = A.size();

    for (int i = 1; i <= 6; i++) {
      int countOfA = 0;
      int countOfB = 0;

      for (int j = 0; j < n; j++) {
        if (A[j] != i && B[j] != i) break;
        if (A[j] == i) countOfA++;
        if (B[j] == i) countOfB++;
        if (j == n - 1) return min(n - countOfA, n - countOfB);
      }
    }

    return -1;
  }
};