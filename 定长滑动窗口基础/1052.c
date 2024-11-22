#include <stdio.h>
int maxSatisfied(int *customers, int customersSize, int *grumpy, int grumpySize, int minutes)
{
    int sum = 0;
    int idx=-1;
    int max = 0;
    for (int i = 0; i < grumpySize; i++)
    {
        if (i < minutes - 1)
        {
            sum += customers[i] * grumpy[i];
            continue;
        }
        sum += customers[i] * grumpy[i];
        if (sum > max)
        {
            max = sum;
            idx = i;
        }
        sum -= customers[i - minutes + 1] * grumpy[i - minutes + 1];
    }
    if(idx!=-1)
    {
        for (int i = idx; i > idx - minutes; i--)
        {
            grumpy[i] = 0;
        }
    }
    int ans = 0;
    for (int i = 0; i < grumpySize; i++)
    {
        if (grumpy[i] == 0)
        {
            ans += customers[i];
        }
    }
    return ans;
}
int main()
{
    int customers[] = {1};
    int grumpy[] = {0};
    int minutes = 1;
    printf("%d", maxSatisfied(customers, 1, grumpy, 1, minutes));
    return 0;
}