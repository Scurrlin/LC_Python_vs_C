class Solution:
    def maxArea(self, height: List[int]) -> int:
        max_area = 0
        left = 0
        right = len(height) - 1

        while left < right:
            area = min(height[left], height[right]) * (right - left)
            max_area = max(max_area, area)

            if height[left] < height[right]:
                left += 1
            else:
                right -= 1
        
        return max_area

# Runtime1: 526ms, beats 51.90%
# Memory1: 29.87MB, beats 25.13%

# Runtime2: 532ms, beats 35.23%
# Memory2: 29.85MB, beats 25.13%

# Runtime3: 531ms, beats 37.75%
# Memory3: 29.88MB, beats 25.13%

# Runtime reduced by a factor of 10 to not skew data visualization