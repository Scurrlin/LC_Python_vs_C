#include <stdio.h>

int search(int* nums, int numsSize, int target) {
    int L = 0, R = numsSize - 1;

    while (L <= R) {
        int mid = L + (R - L) / 2;

        if (nums[mid] == target) {
            return mid;
        }

        if (nums[L] <= nums[mid]) {
            if (target > nums[mid] || target < nums[L]) {
                L = mid + 1;
            } else {
                R = mid - 1;
            }
        }
        else {
            if (target < nums[mid] || target > nums[R]) {
                R = mid - 1;
            } else {
                L = mid + 1;
            }
        }
    }

    return -1;
}

// Runtime1: 0ms, beats 100%
// Memory1: 8.20MB, beats 85.51%

// Runtime2: 0ms, beats 100%
// Memory2: 8.18MB, beats 85.51%

// Runtime3: 0ms, beats 100%
// Memory3: 8.40MB, beats 36.22%