#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution
{
public:
    int longestSubarray(vector<int> &nums)
    {
        int ans=0;
        int left=0;
        unordered_map<int,int> has;
        for(int i=0;i<nums.size();i++)
        {
            has[nums[i]]++;
            while(has[0]>1)
            {
                has[nums[left++]]--;
            }
            int k=i-left+1;
            if(k>ans)
            {
                ans=k;
            }
        }
        if(has[0]==0)
        {
            return ans-1;
        }
        else
        {
            return ans - has[0];
        }
    }
};
int main()
{
    vector<int> nums = { 1, 1, 0, 1 };
    Solution solution;
    cout<<solution.longestSubarray(nums)<<endl;
    return 0;
}