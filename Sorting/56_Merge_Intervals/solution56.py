class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        intervals.sort(key=lambda pair: pair[0])
        output = [intervals[0]]

        for start, end in intervals:
            lastEnd = output[-1][1]

            if start <= lastEnd:
                output[-1][1] = max(lastEnd, end)
            else:
                output.append([start, end])
        return output

# Runtime1: 118ms, beats 82.45%
# Memory1: 21.14MB, beats 27.84%

# Runtime2: 118ms, beats 82.45%
# Memory2: 21.24MB, beats 15.03%

# Runtime3: 120ms, beats 74.19%
# Memory3: 21.18MB, beats 27.84%