int guess(int num);

int guessNumber(int n) {
    int low = 1, high = n, mid;

    while (1) {
        mid = low + (high - low) / 2;
        int res = guess(mid);

        if (res == 0) {
            return mid;
        } else if (res == -1) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
}

// Runtime1: 0ms, beats 100%
// Memory1: 7.56MB, beats 75.71%

// Runtime2:
// Memory2:

// Runtime3:
// Memory3: