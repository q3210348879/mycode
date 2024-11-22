#include <stdio.h>
#include <string.h>
int minimumRecolors(char *blocks, int k)
{
     int count=0;
     int max=0;
     for(int i=0;i<strlen(blocks);i++)
     {
        if(i<k-1)
        {
            if(blocks[i]=='B')
            {
                count++;
            }
            continue;
        }
        if(blocks[i]=='B')
        {
            count++;
        }
        if(count>max)
        {
            max=count;
        }
        if(blocks[i-k+1]=='B')
        {
            count--;
        }
    }
     
     if(max>=k)
     {
        return 0;
     }
     else
     {
        return k-max;
     }
}
int main()
{
    char blocks[] = "WBBWWBBWBW"; 
    int k = 7;
    printf("%d",minimumRecolors(blocks,k));
    return 0;
}