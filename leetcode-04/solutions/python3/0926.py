class Solution:
    def minFlipsMonoIncr(self, S: str) -> int:
        ans = 0
        ones = 0

        for c in S:
            if c == '1':
                ones += 1
            else:
                ans += 1
                ans = min(ans, ones)

        return ans
