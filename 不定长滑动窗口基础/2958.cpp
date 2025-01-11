#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution
{
public:
    int maxSubarrayLength(vector<int> &nums, int k)
    {
        if(nums.size()==1)
        {
            return 1;
        }
        unordered_map<int,int> has;
        int len;
        int max=-1;
        has[nums[0]]++;
        int j=0;
        for(int i=1;i<nums.size();i++)
        {
            has[nums[i]]++;
            while(has[nums[i]]>k)
            {
                has[nums[j]]--;
                j++;
            }
            len=i-j+1;
            if(len>max)
            {
                max=len;
            }
        }
        return max;
    }
};
int main()
{
    Solution s;
    vector<int> nums = { 1, 2, 3, 1, 2, 3, 1, 2 };
    int k=2;
    cout<<s.maxSubarrayLength(nums,k);
    return 0;
}