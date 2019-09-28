class Solution:
    def canReorderDoubled(self, A: List[int]) -> bool:
        dict = collections.Counter(A)

        for key in sorted(dict, key=abs):
            if dict[key] > dict[2 * key]:
                return False
            dict[2 * key] -= dict[key]

        return True
