#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution
{
public:
    long long maxSum(vector<int> &nums, int m, int k)
    {
        long long ans=0,sum=0;
        unordered_map<int, int> cnt;
        for(int i=0;i<k-1;i++)
        {
            sum+=nums[i];
            cnt[nums[i]]++;
        }
        for(int i=k-1;i<nums.size();i++)
        {
            sum+=nums[i];
            cnt[nums[i]]++;
            if(cnt.size()>=m)
            {
                if(sum>ans)
                {
                    ans=sum;
                }
            }
            sum-=nums[i-k+1];
            if(--cnt[nums[i-k+1]]==0)
            {
                cnt.erase(nums[i-k+1]);
            }
        }
        return ans;
    }
};
int main()
{
    vector<int> nums = {2, 6, 7, 3, 1, 7};
    int m = 3;
    int k = 4;
    Solution solution;
    cout<<solution.maxSum(nums,m,k)<<endl;
    return 0;
}