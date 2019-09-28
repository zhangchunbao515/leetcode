class Solution:
    def findRepeatedDnaSequences(self, s: str) -> List[str]:
        ans = set()
        set_ = set()

        for i in range(len(s) - 9):
            seq = s[i:i + 10]
            if seq in set_:
                ans.add(seq)
            set_.add(seq)

        return list(ans)
