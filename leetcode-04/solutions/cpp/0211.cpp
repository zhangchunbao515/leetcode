class TrieNode {
 public:
  TrieNode* get(char c) { return children[c - 'a']; }

  void add(char c) { children[c - 'a'] = new TrieNode; }

  TrieNode* children[26]{};
  bool isLeaf = false;
};

class WordDictionary {
 public:
  WordDictionary() : root(new TrieNode) {}

  ~WordDictionary() { delete root; }

  void addWord(string word) {
    TrieNode* node = root;

    for (char c : word) {
      if (!node->get(c)) node->add(c);
      node = node->get(c);
    }

    node->isLeaf = true;
  }

  bool search(string word) { return search(word, 0, root); }

 private:
  TrieNode* root;

  bool search(string& word, int depth, TrieNode* root) {
    if (depth == word.length()) return root->isLeaf;
    if (word[depth] != '.') {
      root = root->get(word[depth]);
      return root ? search(word, depth + 1, root) : false;
    }

    for (auto i = 0; i < 26; ++i)
      if (root->children[i] && search(word, depth + 1, root->children[i]))
        return true;

    return false;
  }
};