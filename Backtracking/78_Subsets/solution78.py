class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        res = []
        subset = []

        def dfs(i):
            if i >= len(nums):
                res.append(subset.copy())
                return
            subset.append(nums[i])
            dfs(i + 1)
            subset.pop()
            dfs(i + 1)

        dfs(0)
        return res

# Runtime1: 32ms, beats 84.44%
# Memory1: 16.84MB, beats 25.77%

# Runtime2: 33ms, beats 80.25%
# Memory2: 16.83MB, beats 26.83%

# Runtime3: 33ms, beats 80.25%
# Memory3: 16.74MB, beats 26.83%