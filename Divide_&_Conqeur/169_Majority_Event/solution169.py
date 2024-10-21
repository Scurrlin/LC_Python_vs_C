class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        res, count = 0, 0

        for n in nums:
            if count == 0:
                res = n
            count += (1 if n == res else -1)
            
        return res

# Runtime1: 169ms, beats 64.87%
# Memory1: 18.01MB, beats 24.65%

# Runtime2: 158ms, beats 96.30%
# Memory2: 18.09MB, beats 24.65%

# Runtime3: 170ms, beats 60.33%
# Memory3: 18.07MB, beats 24.65%