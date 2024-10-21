class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        res = []

        if len(nums) == 1:
            return [nums[:]]

        for i in range(len(nums)):
            n = nums.pop(0)
            perms = self.permute(nums)

            for perm in perms:
                perm.append(n)
            res.extend(perms)
            nums.append(n)
        return res

# Runtime1: 39ms, beats 66.97%
# Memory1: 16.80MB, beats 34.53%

# Runtime2: 39ms, beats 66.97% 
# Memory2: 16.61MB, beats 70.90%

# Runtime3: 39ms, beats 66.97% 
# Memory3: 16.75MB, beats 34.53%