#include <iostream>
using namespace std;
class Solution
{
public:
    int longestSemiRepetitiveSubstring(string s)
    {
        int count = 1;
        int ans = 0;
        int idx = 1;
        int a[100] = {0};
        int j = 0;
        for (int i = 1; i < s.length(); i++)
        {
            count++;
            // cout << count << endl;
            if (s[i] == s[i - 1])
            {
                a[i - 1] = 1;
                // for (int l = 0; l < 20; l++)
                // {
                //     cout << a[l] << " ";
                //     if (l == 19)
                //     {
                //         cout << endl;
                //     }
                // }
                if (idx == 0)
                {
                    int cnt=0;
                    while (a[j] == 0)
                    {
                        j++;
                        cnt++;
                    }
                    // cout << "j=" << j << endl;
                    // cout << "cnt=" << cnt << endl;
                    a[j] = 0;
                    count = count - cnt -1;
                    j=j+1;
                    // cout << count << endl;
                    if (count > ans)
                    {
                        ans = count;
                    }
                }
                idx = 0;
            }
            if (count > ans)
            {
                ans = count;
            }
            // cout << "done" << endl;
        }
        if (count > ans)
        {
            ans = count;
        }
        return ans;
    }
};
int main()
{
    string s = "2311162506626";
    Solution solution;
    cout << solution.longestSemiRepetitiveSubstring(s) << endl;
    return 0;
}