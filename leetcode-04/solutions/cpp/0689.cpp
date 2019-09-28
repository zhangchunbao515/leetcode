class Solution {
 public:
  vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
    const int n = nums.size();

    vector<int> ans(3);
    vector<int> sum(n + 1);
    vector<int> left(n);
    vector<int> right(n, n - k);
    int max = INT_MIN;

    for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + nums[i - 1];

    int tot = sum[k] - sum[0];

    for (int i = k; i < n; i++) {
      if (sum[i + 1] - sum[i + 1 - k] > tot) {
        left[i] = i + 1 - k;
        tot = sum[i + 1] - sum[i + 1 - k];
      } else {
        left[i] = left[i - 1];
      }
    }

    tot = sum[n] - sum[n - k];

    for (int i = n - k - 1; i >= 0; i--) {
      if (sum[i + k] - sum[i] >= tot) {
        right[i] = i;
        tot = sum[i + k] - sum[i];
      } else {
        right[i] = right[i + 1];
      }
    }

    for (int i = k; i <= n - 2 * k; i++) {
      int l = left[i - 1];
      int r = right[i + k];
      tot = sum[l + k] - sum[l] + (sum[i + k] - sum[i]) + sum[r + k] - sum[r];
      if (tot > max) {
        max = tot;
        ans = {l, i, r};
      }
    }

    return ans;
  }
};