#include <iostream>
using namespace std;
class Solution
{
public:
    int maxConsecutiveAnswers(string answerKey, int k)
    {
        int ans = 0, left = 0;
        int countT = 0, countF = 0; // 统计窗口内'T'和'F'的数量

        for (int right = 0; right < answerKey.length(); right++)
        {
            // 根据当前字符更新 'T' 或 'F' 的计数
            if (answerKey[right] == 'T')
            {
                countT++;
            }
            else
            {
                countF++;
            }

            // 如果 'T' 或 'F' 的数量超过 k，移动左边界缩小窗口
            while (countT > k && countF > k)
            {
                if (answerKey[left] == 'T')
                {
                    countT--;
                }
                else
                {
                    countF--;
                }
                left++;
            }

            // 计算当前窗口的最大长度
            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};
int main()
{
    string answerKey = "TTFF";
    int k=2;
    Solution s;
    cout<<s.maxConsecutiveAnswers(answerKey,k)<<endl;
    return 0;
}