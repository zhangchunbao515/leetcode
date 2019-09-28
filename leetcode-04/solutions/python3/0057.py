class Solution:
    def insert(self, intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:
        ans = []
        index = len(intervals)

        for i in range(len(intervals)):
            if newInterval[0] < intervals[i][0]:
                index = i
                break
        intervals.insert(index, newInterval)

        for interval in intervals:
            if not ans or interval[0] > ans[-1][1]:
                ans.append(interval)
            else:
                ans[-1][1] = max(ans[-1][1], interval[1])

        return ans
