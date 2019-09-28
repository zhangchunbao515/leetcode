class TrieNode {
 public:
  TrieNode* get(char c) { return children[c - 'a']; }

  void add(char c) { children[c - 'a'] = new TrieNode; }

  TrieNode* children[26]{};
  bool isLeaf = false;
};

class Trie {
 public:
  Trie() : root(new TrieNode) {}

  ~Trie() { delete root; }

  void insert(string& word) {
    TrieNode* node = root;

    for (char c : word) {
      if (!node->get(c)) node->add(c);
      node = node->get(c);
    }

    node->isLeaf = true;
  }

  bool search(string& word) {
    TrieNode* node = find(word);

    return node && node->isLeaf;
  }

  bool startsWith(string& prefix) { return find(prefix); }

 private:
  TrieNode* root;

  TrieNode* find(string& key) {
    TrieNode* node = root;

    for (char c : key) {
      if (!node) return NULL;
      node = node->get(c);
    }

    return node;
  }
};

class Solution {
 public:
  vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
    Trie* trie = new Trie;

    for (string& word : words) trie->insert(word);

    unordered_set<string> ans;

    for (int i = 0; i < board.size(); i++)
      for (int j = 0; j < board[0].size(); j++) dfs(board, trie, i, j, "", ans);

    return vector<string>(ans.begin(), ans.end());
  }

 private:
  void dfs(vector<vector<char>>& board, Trie* trie, int i, int j, string path,
           unordered_set<string>& ans) {
    if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() ||
        board[i][j] == '*')
      return;

    path += board[i][j];

    if (!trie->startsWith(path)) return;
    if (trie->search(path)) ans.insert(path);

    char c = board[i][j];
    board[i][j] = '*';

    dfs(board, trie, i + 1, j, path, ans);
    dfs(board, trie, i - 1, j, path, ans);
    dfs(board, trie, i, j + 1, path, ans);
    dfs(board, trie, i, j - 1, path, ans);

    board[i][j] = c;
  }
};