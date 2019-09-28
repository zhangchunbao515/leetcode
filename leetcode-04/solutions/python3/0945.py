class Solution:
    def minIncrementForUnique(self, A: List[int]) -> int:
        ans = 0
        min = 0
        
        A.sort()
        
        for a in A:
            ans += max(min - a, 0)
            min = max(min, a) + 1
        
        return ans