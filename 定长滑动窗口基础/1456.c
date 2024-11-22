#include <stdio.h>
#include <string.h>
int maxVowels(char *s, int k)
{
    int n = strlen(s);
    int count = 0;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (i < k - 1)
        {
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
            {
                count++;
            }
            continue;
        }
        if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
        {
            count++;
 
        }
        if (count > ans)
        {
            ans = count;
        }
        if (s[i - k + 1] == 'a' || s[i - k + 1] == 'e' || s[i - k + 1] == 'i' || s[i - k + 1] == 'o' || s[i - k + 1] == 'u')
        {
            count--;
        }
    }
    return ans;
}
int main()
{
    char s[1000] = {"abciiidef"};
    int k = 3;
    int m = maxVowels(s, k);
    printf("%d", m);
    return 0;
}
