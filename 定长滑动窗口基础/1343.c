#include <stdio.h>
int numOfSubarrays(int *arr, int arrSize, int k, int threshold)
{
    int sum = 0;
    int count = 0;
    for (int i = 0; i < arrSize; i++)
    {
        if (i < k - 1)
        {
            sum += arr[i];
            continue;
        }
        sum += arr[i];
        if (sum >= threshold * k)
        {
            printf("%d\n", sum);
            count++;
        }
        sum -= arr[i - k + 1];
    }
    return count;
}
int main()
{
    int arr[] = {11, 13, 17, 23, 29, 31, 7, 5, 2, 3};
    int k = 3;
    int threshold = 5;
    printf("%d", numOfSubarrays(arr, 10, k, threshold));
    return 0;
}