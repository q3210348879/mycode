#include <iostream>
using namespace std;
class Solution
{
public:
    int longestOnes(vector<int> &nums, int k)
    {
        int ans=1;
        int a=0,b=0;
        int j=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0)
            {
                a++;
            }
            else
            {
                b++;
            }
            while(a>k)
            {
                if(nums[j]==1)
                {
                    b--;
                }
                else
                {
                    a--;
                }
                j++;
            }
            if(i-j+1>ans)
            {
                ans=i-j+1;
            }
        }
        return ans;
    }
};
int main()
{
    vector<int> nums = { 0,0,0,0 };
    int k = 0;
    Solution s;
    cout<<s.longestOnes(nums,k)<<endl;
    return 0;
}