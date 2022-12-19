#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>


int Merge(int* nums, int left, int right, int* tmp)
{
    if (left == right)
        return 0;
    int mid = (right - left) / 2 + left;
    int L = Merge(nums, left, mid, tmp);
    int R = Merge(nums, mid + 1, right, tmp);
    int l1 = left;
    int l2 = mid + 1;
    int sum = 0;
    sum += (L + R);
    int k = l1;
    while (l1 <= mid && l2 <= right)
    {
        if (nums[l1] > nums[l2])
        {
            sum += (mid - l1 + 1);
            tmp[k++] = nums[l2++];
        }
        else
        {
            tmp[k++] = nums[l1++];
        }
    }
    while (l1 <= mid)
        tmp[k++] = nums[l1++];
    while (l2 <= right)
        tmp[k++] = nums[l2++];
    for (int i = left; i <= right; i++)
        nums[i] = tmp[i];
    return sum;
}
int reversePairs(int* nums, int numsSize) {
    if (!numsSize)
        return 0;
    //int* tmp = (int*)malloc(sizeof(int) * numsSize);
    int count = Merge(nums, 0, numsSize - 1, tmp);
    free(tmp);
    return count;
}
int main()
{
    int arr[] = {7,5,6,4};
    reversePairs(arr,4);
    return 0;
}