class Solution:
    def guessNumber(self, n: int) -> int:
        low, high = 1, n
        while (res := guess(mid := ((high + low) >> 1))) != 0:
            if res == -1: high = mid - 1
            else: low = mid + 1
        return mid

# Runtime1: 37ms, beats 38.08%
# Memory1: 16.45MB, beats 68.11%

# Runtime2: 27ms, beats 92.82%
# Memory2: 16.36MB, beats 94.17%

# Runtime3: 23ms, beats 98.27%
# Memory3: 16.37MB, beats 94.17%