class Solution:
    def threeSumClosest(self, nums: List[int], target: int) -> int:
        if len(nums) < 3:
            return 0

        ans = nums[0] + nums[1] + nums[2]

        nums.sort()

        for i in range(len(nums) - 2):
            l = i + 1
            r = len(nums) - 1
            while l < r:
                sum = nums[i] + nums[l] + nums[r]
                if sum == target:
                    return sum
                elif abs(sum - target) < abs(ans - target):
                    ans = sum
                elif sum < target:
                    l += 1
                else:
                    r -= 1

        return ans
