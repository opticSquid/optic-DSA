#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int longestCommonSubsequence(string text1, string text2)
    {
        int n = text1.size(), m = text2.size();
        vector<vector<int>> match(n + 1, vector<int>(m + 1, -1));
        for (int i = 0; i <= n; i++)
        {
            match[i][0] = 0;
        }
        for (int j = 0; j <= m; j++)
        {
            match[0][j] = 0;
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (text1[i - 1] == text2[j - 1])
                {
                    match[i][j] = 1 + match[i - 1][j - 1];
                }
                else
                {
                    match[i][j] = max(match[i - 1][j], match[i][j - 1]);
                }
            }
        }
        return match[n][m];
    }
};
int main()
{
    Solution obj;
    return 0;
}