class Solution {
 public:
  int divide(int dividend, int divisor) {
    if (dividend == INT_MIN && divisor == -1) return INT_MAX;

    long ans = 0;
    long dvd = labs(dividend);
    long dvs = labs(divisor);
    int sign = dividend > 0 ^ divisor > 0 ? -1 : 1;

    while (dvd >= dvs) {
      long m = 1;
      long temp = dvs;
      while (temp << 1 <= dvd) {
        m <<= 1;
        temp <<= 1;
      }
      dvd -= temp;
      ans += m;
    }

    return sign * ans;
  }
};