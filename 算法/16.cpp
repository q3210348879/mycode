#include <iostream>
using namespace std;
class Solution
{
public:
    int threeSumClosest(vector<int> &nums, int target)
    {
        sort(nums.begin(),nums.end());
        int ans=100000;
        int sum=0;
        for(int i=0;i<nums.size();i++)
        {
            if(i<2)
            {
                sum+=nums[i];
                continue;
            }
            sum+=nums[i];
            if (abs(sum - target) < ans)
            {
                ans = abs(sum - target);
            }
            sum-=nums[i-3];
        }
        return ans;
    }
};
int main()
{
    vector<int> nums = { -1, 2, 1, -4 };
    int target = 1;
    Solution s;
    cout<<s.threeSumClosest(nums,target)<<endl;
    return 0;
}