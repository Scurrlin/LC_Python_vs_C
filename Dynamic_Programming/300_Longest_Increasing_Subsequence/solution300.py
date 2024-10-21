class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        LIS = [1] * len(nums)

        for i in range(len(nums) - 1, -1, -1):
            for j in range(i + 1, len(nums)):
                if nums[i] < nums[j]:
                    LIS[i] = max(LIS[i], 1 + LIS[j])
        return max(LIS)

# Runtime1: 1869ms, beats 25.43%
# Memory1: 16.81MB, beats 70.38%

# Runtime2: 1867ms, beats 25.75%
# Memory2: 16.86MB, beats 70.38%

# Runtime3: 1886ms, beats 22.78%
# Memory3: 16.75MB, beats 92.22%

# Runtime reduced by a factor of 10 to not skew data visualization