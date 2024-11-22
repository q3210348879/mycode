#include <stdio.h>
double findMaxAverage(int *nums, int numsSize, int k)
{
    int sum = 0;
    int max = -100000000;
    for (int i = 0; i < numsSize; i++)
    {
        if (i < k - 1)
        {
            sum += nums[i];
            continue;
        }
        sum += nums[i];
        if (sum > max)
        {
            max = sum;
        }
        sum -= nums[i - k + 1];
    }
    return ((double)max / k);
}
int main()
{
    int nums[] = {-1};
    int k = 1;
    printf("%lf", findMaxAverage(nums, 1, k));
    return 0;
}