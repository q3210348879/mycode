#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    vector<int> decrypt(vector<int> &code, int k)
    {
        int n = code.size();
        vector<int> ans(n, 0);
        if (k >= 0)
        {
            for (int i = 0; i < n; i++)
            {
                int sum = 0;
                int m = i;
                for (int j = 0; j < k; j++)
                {
                    sum += code[(m + 1) % n];
                    m++;
                }
                ans[i] = sum;
            }
            return ans;
        }
        else
        {
            for (int i = 0; i < n; i++)
            {
                int sum = 0;
                int m = i;
                for (int j = 0; j < -k; j++)
                {
                    sum += code[(m - 1 + n) % n];
                    m--;
                }
                ans[i] = sum;
            }
            return ans;
        }
    }
};
int main()
{
    vector<int> code = {5, 7, 1, 4};
    int k = -3;
    Solution solution;
    vector<int> ans;
    ans = solution.decrypt(code, k);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}