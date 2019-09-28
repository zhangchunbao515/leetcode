class Solution {
 public:
  vector<string> findRepeatedDnaSequences(string s) {
    const int n = s.length();

    unordered_set<string> ans;
    unordered_set<string> set;

    for (int i = 0; i <= n - 10; i++) {
      string seq = s.substr(i, 10);
      if (set.count(seq)) ans.insert(seq);
      set.insert(seq);
    }

    return vector<string>(ans.begin(), ans.end());
  }
};