class Solution:
    def search(self, nums: List[int], target: int) -> int:
        l, r = 0, len(nums) - 1

        while l <= r:
            m = l + ((r - l) // 2)
            if nums[m] > target:
                r = m - 1
            elif nums[m] < target:
                l = m + 1
            else:
                return m
        return -1

# Runtime1: 189ms, beats 67.96%
# Memory1: 18.10MB, beats 71.59%

# Runtime2: 188ms, beats 73.18%
# Memory2: 18.09MB, beats 71.59%

# Runtime3: 193ms, beats 43.76%
# Memory3: 18.07MB, beats 71.59%