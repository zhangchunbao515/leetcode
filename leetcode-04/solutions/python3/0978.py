class Solution:
    def maxTurbulenceSize(self, A: List[int]) -> int:
        ans = 0
        count = 0

        for i in range(len(A) - 1):
            if A[i] > A[i + 1]:
                count = count + 1 if count > 0 else 1
            elif A[i] < A[i + 1]:
                count = count - 1 if count < 0 else -1
            else:
                count = 0
            ans = max(ans, abs(count))
            count *= -1

        return ans + 1
