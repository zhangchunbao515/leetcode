class Solution:
    def minDominoRotations(self, A: List[int], B: List[int]) -> int:
        for x in range(1, 7):
            if all(a == x or b == x for a, b in zip(A, B)):
                return min(len(A) - A.count(x), len(B) - B.count(x))

        return -1
