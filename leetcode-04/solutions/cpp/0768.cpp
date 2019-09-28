class Solution {
 public:
  int maxChunksToSorted(vector<int>& arr) {
    const int n = arr.size();

    int ans = 0;
    vector<int> min(n);
    min[n - 1] = arr[n - 1];
    int max = INT_MIN;

    for (int i = n - 2; i >= 0; i--) min[i] = std::min(min[i + 1], arr[i]);

    for (int i = 0; i < n - 1; i++) {
      max = std::max(max, arr[i]);
      if (max <= min[i + 1]) ans++;
    }

    return ans + 1;
  }
};