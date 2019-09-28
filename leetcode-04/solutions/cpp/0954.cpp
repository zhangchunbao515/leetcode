class Solution {
 public:
  bool canReorderDoubled(vector<int>& A) {
    unordered_map<int, int> map;
    for (int a : A) map[a]++;

    vector<int> keys;

    for (auto& [key, _] : map) keys.push_back(key);

    sort(keys.begin(), keys.end(),
         [](int a, int b) { return abs(a) < abs(b); });

    for (int key : keys) {
      if (map[key] > map[2 * key]) return false;
      map[2 * key] -= map[key];
    }

    return true;
  }
};