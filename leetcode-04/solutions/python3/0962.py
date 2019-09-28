class Solution:
    def maxWidthRamp(self, A: List[int]) -> int:
        ans = 0
        stack = []

        for i, a in enumerate(A):
            if not stack or a < A[stack[-1]]:
                stack.append(i)

        for j in range(len(A))[::-1]:
            while stack and A[stack[-1]] <= A[j]:
                ans = max(ans, j - stack.pop())

        return ans
