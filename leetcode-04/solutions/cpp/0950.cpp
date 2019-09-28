class Solution {
 public:
  vector<int> deckRevealedIncreasing(vector<int>& deck) {
    sort(deck.rbegin(), deck.rend());

    deque<int> deque;
    deque.push_back(deck[0]);

    for (int i = 1; i < deck.size(); i++) {
      deque.push_front(deque.back());
      deque.pop_back();
      deque.push_front(deck[i]);
    }

    return vector<int>(deque.begin(), deque.end());
  }
};