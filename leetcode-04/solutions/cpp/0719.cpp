class Solution {
 public:
  int smallestDistancePair(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());

    int l = 0;
    int r = nums.back() - nums.front();

    while (l < r) {
      int m = l + (r - l) / 2;
      int count = 0;
      int j = 0;

      for (int i = 0; i < nums.size(); i++) {
        while (j < nums.size() && nums[i] + m >= nums[j]) j++;
        count += j - i - 1;
      }

      count < k ? l = m + 1 : r = m;
    }

    return l;
  }
};