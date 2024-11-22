#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
class Solution
{
public:
    int maximumLengthSubstring(string s)
    {
        int ans=0;
        int left=0;
        unordered_map<char,int> has;
        for(int i=0;i<s.length();i++)
        {
            char c=s[i];
            has[c]++;
            while(has[c]>2)
            {
                has[s[left++]]--;
            }
            int k=i-left+1;
            if(k>ans)
            {
                ans=k;
            }
        }
        return ans;
    }
};
int main()
{
    string s = "bacbbbcba";
    Solution solution;
    cout<<solution.maximumLengthSubstring(s)<<endl;
    return 0;
}