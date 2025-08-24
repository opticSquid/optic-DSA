#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        vector<int> prevRow(n, 0);
        for (int i = 0; i < m; i++)
        {
            vector<int> currRow(n, 0);
            for (int j = 0; j < n; j++)
            {
                if (i == 0 && j == 0)
                {
                    currRow[j] = 1;
                }
                else
                {
                    int u = 0, l = 0;
                    if (i > 0)
                        u = prevRow[j];
                    if (j > 0)
                        l = currRow[j - 1];
                    currRow[j] = u + l;
                }
            }
            prevRow = currRow;
        }
        return prevRow[n - 1];
    }
};
int main()
{
    Solution obj;
    return 0;
}