#include <iostream>
#include <unordered_map>
using namespace std;
class Solution
{
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize)
    {
        unordered_map<string,int> hash;
        for(int i=0;i<s.size();i++)
        {
            
        }
    }
};
int main()
{
    string s = "aababcaab";
    int maxLetters = 2,minSize = 3, maxSize = 4;
    Solution sulution;
    cout<<sulution.maxFreq(s,maxLetters,minSize,maxSize)<<endl;
    return 0;
}