#include <iostream>
#include <cmath>
using namespace std;
class Solution
{
public:
    int equalSubstring(string s, string t, int maxCost)
    {
        int count=0;
        int sum=0;
        int ans=0;
        for(int i=0;i<s.length();i++)
        {
            count++;
            sum+=abs(s[i]-t[i]);
            while(sum>maxCost)
            {
                sum-=abs(s[i-count+1]-t[i-count+1]);
                count--;
            }
            if(count>ans)
            {
                ans=count;
            }
        }
        return ans;
    }
};
int main()
{
    string s = "abcd", t = "bcdf";
    int maxCost = 3;
    Solution solution;
    cout<<solution.equalSubstring(s,t,maxCost)<<endl;
    return 0;
}