#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        int paths[m][n];
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == 0 && j == 0)
                {
                    paths[i][j] = 1;
                }
                else
                {
                    int u = 0, l = 0;
                    if (i > 0)
                        u = paths[i - 1][j];
                    if (j > 0)
                        l = paths[i][j - 1];
                    paths[i][j] = u + l;
                }
            }
        }
        return paths[m - 1][n - 1];
    }
};
int main()
{
    Solution obj;
    return 0;
}