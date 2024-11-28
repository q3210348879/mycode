#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution
{
public:
    int totalFruit(vector<int> &fruits)
    {
        unordered_map<int, int> has;
        int left = 0;
        int ans = 0;
        for (int i = 0; i < fruits.size(); i++)
        {
            has[fruits[i]]++;
            while (has.size() > 2)
            {
                has[fruits[left]]--;
                if (has[fruits[left]] == 0)
                {
                    has.erase(fruits[left]);
                }
                left++;
            }
            // int sum=0;
            // for(auto it=has.begin();it!=has.end();it++)
            // {
            //     sum+=it->second;
            // }
            if (i - left + 1 > ans)
            {
                ans = i - left + 1;
            }
        }
        return ans;
    }
};
int main()
{
    vector<int> fruits = {3, 3, 3, 1, 2, 1, 1, 2, 3, 3, 4};
    Solution solution;
    cout << solution.totalFruit(fruits) << endl;
    return 0;
}