#include <stdio.h>

int min(int a, int b) {
    return (a < b) ? a : b;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

int maxArea(int* height, int heightSize) {
    int max_area = 0;
    int left = 0;
    int right = heightSize - 1;

    while (left < right) {
        int area = min(height[left], height[right]) * (right - left);
        max_area = max(max_area, area);

        if (height[left] < height[right]) {
            left++;
        } else {
            right--;
        }
    }

    return max_area;
}

// Runtime1: 3ms, beats 95.89%
// Memory1: 13.90MB, beats 36.33%

// Runtime2: 4ms, beats 95.46%
// Memory2: 13.87MB, beats 58.43%

// Runtime3: 0ms, beats 100%
// Memory3: 14.15MB, beats 8.35%

// Runtime reduced by a factor of 10 to not skew data visualization