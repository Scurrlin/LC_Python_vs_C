class Solution:
    def insert(self, intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:
        res = []

        for i in range(len(intervals)):
            if newInterval[1] < intervals[i][0]:
                res.append(newInterval)
                return res + intervals[i:]
            elif newInterval[0] > intervals[i][1]:
                res.append(intervals[i])
            else:
                newInterval = [
                    min(newInterval[0], intervals[i][0]),
                    max(newInterval[1], intervals[i][1]),
                ]
        res.append(newInterval)
        return res

# Runtime1: 70ms, beats 83.71%
# Memory1: 19.96MB, beats 19.68%

# Runtime2: 68ms, beats 89.76%
# Memory2: 19.97MB, beats 19.68%

# Runtime3: 68ms, beats 89.76%
# Memory3: 19.90MB, beats 77.20%