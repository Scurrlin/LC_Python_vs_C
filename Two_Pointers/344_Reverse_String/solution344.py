class Solution:
    def reverseString(self, s: List[str]) -> None:
        l, r = 0, len(s) - 1
        while l < r:
            s[l], s[r] = s[r], s[l]
            l += 1
            r -= 1

# Runtime1: 172ms, beats 39.07%
# Memory1: 20.89MB, beats 34.11%

# Runtime2: 172ms, beats 39.07%
# Memory2: 20.86MB, beats 34.11%

# Runtime3: 175ms, beats 23.02%
# Memory3: 20.80MB, beats 34.11%