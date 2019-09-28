class Solution:
    def commonChars(self, A: List[str]) -> List[str]:
        ans = []
        commonCount = [float('inf')] * 26

        for a in A:
            count = [0] * 26
            for c in a:
                count[ord(c) - ord('a')] += 1
            for i in range(26):
                commonCount[i] = min(commonCount[i], count[i])

        for i in range(26):
            for j in range(commonCount[i]):
                ans.append(chr(i + ord('a')))

        return ans
