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

// Runtime1: 0ms, beats 100%
// Memory1: 10MB, beats 91.26%

// Runtime2: 0ms, beats 100%
// Memory2: 10.06MB, beats 63.65%

// Runtime3: 0ms, beats 100%
// Memory3: 10.40MB, beats 20.56%