/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdlib.h>

int findFirst(int* nums, int numsSize, int target) {
    int left = 0;
    int right = numsSize - 1;
    int index = -1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] >= target) {
            if (nums[mid] == target) {
                index = mid;
            }
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    
    return index;
}

int findLast(int* nums, int numsSize, int target) {
    int left = 0;
    int right = numsSize - 1;
    int index = -1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] <= target) {
            if (nums[mid] == target) {
                index = mid;
            }
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    return index;
}

int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
    int* result = (int*)malloc(2 * sizeof(int));
    *returnSize = 2;
    
    result[0] = findFirst(nums, numsSize, target);
    result[1] = findLast(nums, numsSize, target);
    
    return result;
}