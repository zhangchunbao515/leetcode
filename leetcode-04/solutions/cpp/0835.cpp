class Solution {
 public:
  int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
    int ans = 0;
    vector<vector<int>> onesA;
    vector<vector<int>> onesB;
    unordered_map<int, int> map;
    const int magic = 907;

    for (int i = 0; i < A.size(); i++)
      for (int j = 0; j < A[0].size(); j++) {
        if (A[i][j]) onesA.push_back({i, j});
        if (B[i][j]) onesB.push_back({i, j});
      }

    for (vector<int>& a : onesA)
      for (vector<int>& b : onesB) map[(a[0] - b[0]) * magic + (a[1] - b[1])]++;

    for (auto& [_, value] : map) ans = max(ans, value);

    return ans;
  }
};