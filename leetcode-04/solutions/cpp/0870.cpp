class Solution {
 public:
  vector<int> advantageCount(vector<int>& A, vector<int>& B) {
    multiset<int> set(A.begin(), A.end());

    for (int i = 0; i < B.size(); i++) {
      auto p = *set.rbegin() <= B[i] ? set.begin() : set.upper_bound(B[i]);
      A[i] = *p;
      set.erase(p);
    }

    return A;
  }
};