class Solution:
    def rob(self, nums: List[int]) -> int:
        rob1, rob2 = 0, 0

        for n in nums:
            temp = max(n + rob1, rob2)
            rob1 = rob2
            rob2 = temp
        return rob2

# Runtime1: 30ms, beats 89.63%
# Memory1: 16.44MB, beats 70.50%

# Runtime2: 34ms, beats 70.87%
# Memory2: 16.46MB, beats 70.50%

# Runtime3: 25ms, beats 97.97%
# Memory3: 16.56MB, beats 28.72%