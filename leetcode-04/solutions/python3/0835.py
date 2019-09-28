class Solution:
    def largestOverlap(self, A: List[List[int]], B: List[List[int]]) -> int:
        onesA = []
        onesB = []
        dict = collections.defaultdict(int)
        magic = 907

        for i in range(len(A)):
            for j in range(len(A[0])):
                if A[i][j]:
                    onesA.append([i, j])
                if B[i][j]:
                    onesB.append([i, j])

        for a in onesA:
            for b in onesB:
                dict[(a[0] - b[0]) * magic + (a[1] - b[1])] += 1

        return max(dict.values()) if dict else 0
