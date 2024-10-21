class Solution:
    def canJump(self, nums: List[int]) -> bool:
        goal = len(nums) - 1

        for i in range(len(nums) - 2, -1, -1):
            if i + nums[i] >= goal:
                goal = i
        return goal == 0

# Runtime1: 352ms, beats 65.81%
# Memory1: 17.80MB, beats 68.74%

# Runtime2: 348ms, beats 74.32%
# Memory2: 17.80MB, beats 68.74%

# Runtime3: 343ms, beats 85.72%
# Memory3: 17.79MB, beats 68.74%

# Runtime reduced by a factor of 10 to not skew data visualization