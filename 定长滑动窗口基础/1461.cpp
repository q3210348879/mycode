#include <iostream>
#include <unordered_set>
#include <string>
using namespace std;

class Solution {
public:
    bool hasAllCodes(string s, int k) {
        // 如果字符串长度不足以包含所有长度为 k 的子串，则直接返回 false
        if (s.size() < k) return false;

        unordered_set<string> substrings; // 用于存储长度为 k 的子串

        // 滑动窗口遍历所有长度为 k 的子串
        for (int i = 0; i <= s.size() - k; i++) {
            substrings.insert(s.substr(i, k)); // 插入子串到哈希表中
        }

        // 判断哈希表中子串数量是否等于所有可能的二进制字符串数量 2^k
        return substrings.size() == (1 << k);
    }
};

int main() {
    Solution solution;
    string s = "00110110";
    int k = 2;

    // 调用函数并输出结果
    cout << (solution.hasAllCodes(s, k) ? "true" : "false") << endl;

    return 0;
}
int main()
{
    string s = "00110110";
    int k = 2;
    Solution solution;
    cout<<solution.hasAllCodes(s,k)<<endl;
    return 0;
}