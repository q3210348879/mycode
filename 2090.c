#include <stdio.h>
#include <stdlib.h>
int *getAverages(int *nums, int numsSize, int k, int *returnSize)
{
    int *array = (int *)malloc(numsSize * sizeof(int));
    for (int i = 0; i < numsSize; i++)
    {
        array[i] = -1;
    }
    *returnSize = numsSize;
    long long len = 2 * k + 1;
    long long sum = 0;
    for (int i = 0; i < numsSize; i++)
    {
        if (i < len - 1)
        {
            sum += nums[i];
            continue;
        }
        sum += nums[i];
        array[i - k] = sum / len;
        sum -= nums[i - len + 1];
    }
    return array;
}
int main()
{
    int nums[] = {7, 4, 3, 9, 1, 8, 5, 2, 6 };
    int result[1];
    int k = 3;
    for(int i=0;i<9;i++)
    {
        printf("%d ",getAverages(nums,9,k,result)[i]);
    }
    return 0;
}