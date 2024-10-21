class Solution:
    def findMinArrowShots(self, points: List[List[int]]) -> int:
        if not points:
            return 0

        points.sort(key=lambda x: x[1])

        arrows = 1
        end = points[0][1]

        for start, finish in points:
            if start > end:
                arrows += 1
                end = finish

        return arrows

# Runtime1: 1015ms, beats 83.31%
# Memory1: 62.88MB, beats 21.51%

# Runtime2: 980ms, beats 98.10%
# Memory2: 62.23MB, beats 92.35%

# Runtime3: 1015ms, beats 83.31%
# Memory3: 62.81MB, beats 21.51%

# Runtime reduced by a factor of 10 to not skew data visualization