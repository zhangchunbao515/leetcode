class Solution {
 public:
  vector<string> commonChars(vector<string>& A) {
    vector<string> ans;
    vector<int> commonCount(26, INT_MAX);

    for (string& a : A) {
      vector<int> count(26);
      for (char c : a) count[c - 'a']++;
      for (int i = 0; i < 26; i++)
        commonCount[i] = min(commonCount[i], count[i]);
    }

    for (int i = 0; i < 26; i++)
      for (int j = 0; j < commonCount[i]; j++)
        ans.push_back(string(1, i + 'a'));

    return ans;
  }
};