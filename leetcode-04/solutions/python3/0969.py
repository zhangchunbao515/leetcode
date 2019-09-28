class Solution:
    def pancakeSort(self, A: List[int]) -> List[int]:
        n = len(A)

        ans = []
        target = n

        for i in range(n):
            index = A.index(target) + 1
            A[:index] = A[:index][::-1]
            A[:target] = A[:target][::-1]
            ans.append(index)
            ans.append(target)
            target -= 1

        return ans
