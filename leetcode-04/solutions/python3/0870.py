class Solution:
    def advantageCount(self, A: List[int], B: List[int]) -> List[int]:
        A.sort()
        dict = collections.defaultdict(list)

        for b in sorted(B)[::-1]:
            if b < A[-1]:
                dict[b].append(A.pop())

        return [(dict[b] or A).pop() for b in B]
