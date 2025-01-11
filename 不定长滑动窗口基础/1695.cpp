#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution
{
public:
    int maximumUniqueSubarray(vector<int> &nums)
    {
        if(nums.size()==1)
        {
            return nums[0];
        }
        int sum = 0;
        sum = nums[0];
        unordered_map<int, int> has;
        has[nums[0]]++;
        int j = 0;
        int max = -1;
        for (int i = 1; i < nums.size(); i++)
        {
            has[nums[i]]++;
            sum += nums[i];
            while (has[nums[i]] > 1)
            {
                has[nums[j]]--;
                sum -= nums[j];
                j++;
            }
            if (sum > max)
            {
                max = sum;
            }
        }
        return max;
    }
};
int main()
{
    vector<int> nums = {10000};
    Solution s;
    cout << s.maximumUniqueSubarray(nums) << endl;
    return 0;
}