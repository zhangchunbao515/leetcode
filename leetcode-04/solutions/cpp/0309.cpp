class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    int sell = 0;
    int hold = INT_MIN;
    int prev = 0;

    for (int price : prices) {
      int cache = sell;
      sell = max(sell, hold + price);
      hold = max(hold, prev - price);
      prev = cache;
    }

    return sell;
  }
};