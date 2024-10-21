class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        res = nums[0]
        total = 0
        for n in nums:
            total += n
            res = max(res, total)
            if total < 0:
                total = 0
        return res

# Runtime1: 513ms, beats 77.07%
# Memory1: 30.79MB, beats 97.77%

# Runtime2: 516ms, beats 73.63%
# Memory2: 30.86MB, beats 91.98%

# Runtime3: 507ms, beats 82.05%
# Memory3: 30.93MB, beats 71.88%

# Runtime reduced by a factor of 10 to not skew data visualization