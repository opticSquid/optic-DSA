#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int minDistance(string word1, string word2)
    {
        int n = word1.size(), m = word2.size();
        if (n == 0)
        {
            return m;
        }
        if (m == 0)
        {
            return n;
        }
        int ops[n + 1][m + 1];
        memset(ops, 0, sizeof(ops));
        for (int i = 0; i < n; i++)
        {
            ops[i][0] = i;
        }
        for (int j = 0; j < m; j++)
        {
            ops[0][j] = j;
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (word1[i - 1] == word2[j - 1])
                {
                    ops[i][j] = ops[i - 1][j - 1];
                }
                else
                {
                    int ins = ops[i][j - 1];
                    int del = ops[i - 1][j];
                    int rep = ops[i - 1][j - 1];
                    ops[i][j] = 1 + min(ins, min(del, rep));
                }
            }
        }
        return ops[n][m];
    }
};
int main()
{
    Solution obj;
    return 0;
}