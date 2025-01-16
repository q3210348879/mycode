#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int maximumBeauty(vector<int> &nums, int k)
    {
        sort(nums.begin(),nums.end());
        int max=1;
        int j=0;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]-k<=nums[j]+k)
            {
                if(i-j+1>max)
                {
                    max=i-j+1;
                }
            }
            else
            {
                while (nums[i] - k > nums[j] + k)
                {
                    j++;
                }
            }
        }
        return max;
    }
};
int main()
{
    Solution s;
    vector<int> nums = { 4, 6, 1, 2 };
    int k = 2;
    cout<<s.maximumBeauty(nums,k)<<endl;
    return 0;
}