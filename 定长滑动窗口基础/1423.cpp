#include <iostream>
using namespace std;
class Solution
{
public:
    int maxScore(vector<int> &cardPoints, int k)
    {
        int n = cardPoints.size();
        int sum = 0;
        long long min = 1000000000000;
        for (int i = 0; i < n; i++)
        {
            if (i < n - k - 1)
            {
                sum += cardPoints[i];
                continue;
            }
            sum += cardPoints[i];
            if (sum < min)
            {
                min = sum;
            }
            sum -= cardPoints[i - (n - k) + 1];
        }
        int allsum = 0;
        for (int i = 0; i < n; i++)
        {
            allsum += cardPoints[i];
        }
        if (n != k)
        {
            return allsum - min;
        }
        else
        {
            return allsum;
        }
    }
};
int main()
{
    vector<int> cardPoints = {1, 2, 3, 4, 5, 6, 1};
    int k = 3;
    Solution solution;
    cout << solution.maxScore(cardPoints, k) << endl;
    return 0;
}