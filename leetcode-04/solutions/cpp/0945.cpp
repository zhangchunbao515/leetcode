class Solution {
 public:
  int minIncrementForUnique(vector<int>& A) {
    int ans = 0;
    int min = 0;

    sort(A.begin(), A.end());

    for (int a : A) {
      ans += max(min - a, 0);
      min = max(min, a) + 1;
    }

    return ans;
  }
};