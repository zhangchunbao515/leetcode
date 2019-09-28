class Solution {
 public:
  vector<int> pancakeSort(vector<int>& A) {
    const int n = A.size();

    vector<int> ans;
    int target = n;

    for (int i = 0; i < n; i++) {
      int index = find(A, target);
      reverse(A.begin(), A.begin() + index);
      reverse(A.begin(), A.begin() + target);
      ans.push_back(index);
      ans.push_back(target--);
    }

    return ans;
  }

 private:
  int find(vector<int>& A, int target) {
    for (int i = 0; i < A.size(); i++)
      if (A[i] == target) return i + 1;
    return -1;
  }
};