#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution
{
public:
    long long maximumSubarraySum(vector<int> &nums, int k)
    {
        int sum=0;
        int ans=0;
        unordered_map<int,int> s ;
        for(int i=0;i<nums.size();i++)
        {
            if(i<k-1)
            {
                sum+=nums[i];
                s[nums[i]]++;
                continue;
            }
            sum+=nums[i];
            s[nums[i]]++;
            if(s.size()==k)
            {
                if(sum>ans)
                {
                    ans=sum;
                }
            }
            sum-=nums[i-k+1];
            if(--s[nums[i-k+1]]==0)
            {
                s.erase(nums[i-k+1]);
            }
        }
        return ans;
    }
};
int main()
{
    vector<int> nums= { 1, 5, 4, 2, 9, 9, 9 };
    int k = 3;
    Solution solution;
    cout << solution.maximumSubarraySum(nums, k) << endl;
    return 0;
}