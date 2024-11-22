#include <iostream>
#include <unordered_set>
using namespace std;
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        unordered_set<char> has;
        int ans=0,left=0;
        for(int i=0;i<s.length();i++)
        {
           char c=s[i];
           while(has.count(c))
           {
            has.erase(s[left]);
            left++;
           }
           has.insert(c);
            if(i-left+1>ans)
            {
                ans=i-left+1;
            }
        }
        return ans;
    }
    
};
int main()
{
    string s = "abcabcbb";
    Solution solution;
    cout<<solution.lengthOfLongestSubstring(s)<<endl;
    return 0;
}