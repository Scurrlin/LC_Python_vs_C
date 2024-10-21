int majorityElement(int* nums, int numsSize) {
    int res = 0, count = 0;

    for (int i = 0; i < numsSize; ++i) {
        if (count == 0) {
            res = nums[i];
        }
        count += (nums[i] == res) ? 1 : -1;
    }

    return res;
}

// Runtime1:
// Memory1:

// Runtime2:
// Memory2:

// Runtime3:
// Memory3: