class Solution {
 public:
  int subarraysDivByK(vector<int>& A, int K) {
    int ans = 0;
    int sum = 0;
    vector<int> map(K);
    map[0] = 1;

    for (int a : A) {
      sum = (sum + a) % K;
      if (sum < 0) sum += K;
      ans += map[sum];
      map[sum]++;
    }

    return ans;
  }
};