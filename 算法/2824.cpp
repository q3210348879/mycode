#include <iostream>
using namespace std;
class Solution
{
public:
    int countPairs(vector<int> &nums, int target)
    {
        int ans=0;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        for(int i=0;i<n-1;i++)
        {
            int r=n-1;
            while(nums[i]+nums[r]>=target&&i<r)
            {
                r--;
            }
            if(i==r)
            {
                break;
            }
            ans+=r-i;
        }
        return ans;
    }
};
int main()
{
    Solution s;
    int target=2;
    vector<int> nums={-1,1,2,3,1};
    cout<<s.countPairs(nums,target);
    return 0;
}