class Solution:
    def partitionDisjoint(self, A: List[int]) -> int:
        n = len(A)

        min_ = [0] * (n - 1) + [A[-1]]
        max_ = float('-inf')

        for i in range(n - 2, -1, -1):
            min_[i] = min(min_[i + 1], A[i])

        for i in range(n - 1):
            max_ = max(max_, A[i])
            if max_ <= min_[i + 1]:
                return i + 1
