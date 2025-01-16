#include <iostream>
#include <numeric>
#include <vector>
using namespace std;
class Solution
{
public:
    int minOperations(vector<int> &nums, int x)
    {
        int ans = -1;
        int sum = 0;
        int j = 0;
        int a = accumulate(nums.begin(), nums.end(), 0);
        if (a - x < 0)
            return -1;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            while (sum > a - x)
            {
                sum -= nums[j];
                j++;
            }
            if (sum == a - x)
            {
                if (i - j + 1 > ans)
                {
                    ans = i - j + 1;
                }
            }
        }
        return ans < 0 ? -1 : nums.size() - ans;
    }
};
int main()
{
    Solution s;
    vector<int> nums = {1, 1, 4, 2, 3 };
    int x = 5;
    cout<<s.minOperations(nums,x)<<endl;
    return 0;
}