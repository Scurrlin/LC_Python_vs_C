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

// Runtime1:
// Memory1:

// Runtime2:
// Memory2:

// Runtime3:
// Memory3: