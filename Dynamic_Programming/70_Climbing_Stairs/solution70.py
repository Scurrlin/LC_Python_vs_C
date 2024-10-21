class Solution:
    def climbStairs(self, n: int) -> int:
        dp = [0] * (n + 1)
        dp[0] = 1
        dp[1] = 1

        for i in range(2, n + 1):
            dp[i] = dp[i-1] + dp[i-2]
        
        return dp[-1]

# Runtime1: 33ms, beats 66.88%
# Memory1: 16.68MB, beats 15.96%

# Runtime2: 35ms, beats 50.71%
# Memory2: 16.51MB, beats 15.96%

# Runtime3: 32ms, beats 73.93%
# Memory3: 16.48MB, beats 63.27%