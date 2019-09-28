class Solution:
    def maxChunksToSorted(self, arr: List[int]) -> int:
        n = len(arr)

        ans = 0
        min_ = [0] * (n - 1) + [arr[-1]]
        max_ = float('-inf')

        for i in range(n - 2, -1, -1):
            min_[i] = min(min_[i + 1], arr[i])

        for i in range(n - 1):
            max_ = max(max_, arr[i])
            if max_ <= min_[i + 1]:
                ans += 1

        return ans + 1
