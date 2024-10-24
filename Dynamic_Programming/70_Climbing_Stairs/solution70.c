#include <stdio.h>
#include <stdlib.h>

int climbStairs(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }

    int* dp = (int*)malloc((n + 1) * sizeof(int));
    
    dp[0] = 1;
    dp[1] = 1;

    for (int i = 2; i <= n; ++i) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    int result = dp[n];

    free(dp);

    return result;
}

// Runtime1: 0ms, beats 100%
// Memory1: 7.81MB, beats 18.15%

// Runtime2: 0ms, beats 100%
// Memory2: 7.92MB, beats 18.15%

// Runtime3: 0ms, beats 100%
// Memory3: 7.76MB, beats 38.26%