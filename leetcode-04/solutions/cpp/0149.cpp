class Solution {
 public:
  int maxPoints(vector<vector<int>>& points) {
    int ans = 0;

    for (int i = 0; i < points.size(); i++) {
      map<pair<int, int>, int> map;
      vector<int> p1 = points[i];
      int samePoints = 1;
      int maxPoints = 0;
      for (int j = i + 1; j < points.size(); j++) {
        vector<int> p2 = points[j];
        if (p1[0] == p2[0] && p1[1] == p2[1])
          samePoints++;
        else
          maxPoints = max(maxPoints, ++map[getSlope(p1, p2)]);
      }
      ans = max(ans, samePoints + maxPoints);
    }

    return ans;
  }

 private:
  pair<int, int> getSlope(vector<int>& p1, vector<int>& p2) {
    int dx = p2[0] - p1[0];
    int dy = p2[1] - p1[1];

    if (dy == 0) return {p1[1], 0};
    if (dx == 0) return {0, p1[0]};

    int d = gcd(dx, dy);

    return {dy / d, dx / d};
  }

  int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
};