class Solution:
    def deckRevealedIncreasing(self, deck: List[int]) -> List[int]:
        deque = collections.deque()

        for card in sorted(deck)[::-1]:
            deque.rotate()
            deque.appendleft(card)

        return list(deque)
