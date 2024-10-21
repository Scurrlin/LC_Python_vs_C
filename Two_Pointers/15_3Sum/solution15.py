class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        res = []
        nums.sort()

        for i in range(len(nums)):
            if i > 0 and nums[i] == nums[i-1]:
                continue
            
            j = i + 1
            k = len(nums) - 1

            while j < k:
                total = nums[i] + nums[j] + nums[k]

                if total > 0:
                    k -= 1
                elif total < 0:
                    j += 1
                else:
                    res.append([nums[i], nums[j], nums[k]])
                    j += 1

                    while nums[j] == nums[j-1] and j < k:
                        j += 1
        
        return res

# Runtime1: 674ms, beats 70.08%
# Memory1: 20.68MB, beats 73.19%

# Runtime2: 691ms, beats 62.27%
# Memory2: 20.81MB, beats 19.44%

# Runtime3: 689ms, beats 63.17%
# Memory3: 20.73MB, beats 33.88%

# Runtime reduced by a factor of 10 to not skew data visualization