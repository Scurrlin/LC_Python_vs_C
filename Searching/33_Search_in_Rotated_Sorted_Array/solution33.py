class Solution:
    def search(self, nums: List[int], target: int) -> int:
        L, R = 0, len(nums) - 1

        while L <= R:
            mid = (L + R) // 2
            if target == nums[mid]:
                return mid

            if nums[L] <= nums[mid]:
                if target > nums[mid] or target < nums[L]:
                    L = mid + 1
                else:
                    R = mid - 1
            else:
                if target < nums[mid] or target > nums[R]:
                    R = mid - 1
                else:
                    L = mid + 1
        return -1

# Runtime1: 43ms, beats 57.45%
# Memory1: 16.83MB, beats 73.04%

# Runtime2: 37ms, beats 89.99%
# Memory2: 16.88MB, beats 72.42%

# Runtime3: 42ms, beats 67.07%
# Memory3: 16.95MB, beats 33.05%