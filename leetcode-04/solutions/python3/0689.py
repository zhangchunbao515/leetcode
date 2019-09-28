class Solution:
    def maxSumOfThreeSubarrays(self, nums: List[int], k: int) -> List[int]:
        n = len(nums)

        ans = [0] * 3
        sum = [0] * (n + 1)
        left = [0] * n
        right = [n - k] * n
        max_ = float('-inf')

        for i in range(1, n + 1):
            sum[i] = sum[i - 1] + nums[i - 1]

        tot = sum[k] - sum[0]

        for i in range(k, n):
            if sum[i + 1] - sum[i + 1 - k] > tot:
                left[i] = i + 1 - k
                tot = sum[i + 1] - sum[i + 1 - k]
            else:
                left[i] = left[i - 1]

        tot = sum[n] - sum[n - k]

        for i in range(n - k - 1, -1, -1):
            if sum[i + k] - sum[i] >= tot:
                right[i] = i
                tot = sum[i + k] - sum[i]
            else:
                right[i] = right[i + 1]

        for i in range(k, n - 2 * k + 1):
            l = left[i - 1]
            r = right[i + k]
            tot = (sum[l + k] - sum[l]) + \
                (sum[i + k] - sum[i]) + (sum[r + k] - sum[r])
            if tot > max_:
                max_ = tot
                ans = [l, i, r]

        return ans
