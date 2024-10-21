class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        charSet = set()
        l = 0
        res = 0

        for r in range(len(s)):
            while s[r] in charSet:
                charSet.remove(s[l])
                l += 1
            charSet.add(s[r])
            res = max(res, r - l + 1)
        return res

# Runtime1: 53ms, beats 68.95%
# Memory1: 16.54MB, beats 82.45%

# Runtime2: 52ms, beats 73.18%
# Memory2: 16.53MB, beats 82.45%

# Runtime3: 53ms, beats 68.95%
# Memory3: 16.56MB, beats 82.45%