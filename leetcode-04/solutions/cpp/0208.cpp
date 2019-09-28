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

  void insert(string word) {
    TrieNode* node = root;

    for (char c : word) {
      if (!node->get(c)) node->add(c);
      node = node->get(c);
    }

    node->isLeaf = true;
  }

  bool search(string word) {
    TrieNode* node = find(word);

    return node && node->isLeaf;
  }

  bool startsWith(string prefix) { return find(prefix); }

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