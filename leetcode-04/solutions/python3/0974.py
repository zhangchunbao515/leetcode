class Solution:
    def subarraysDivByK(self, A: List[int], K: int) -> int:
        ans = 0
        sum = 0
        map = [1] + [0] * (K - 1)

        for a in A:
            sum = (sum + a) % K
            ans += map[sum]
            map[sum] += 1

        return ans
