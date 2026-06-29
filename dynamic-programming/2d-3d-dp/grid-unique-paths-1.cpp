#include <bits/stdc++.h>
#include <cassert>
using namespace std;
class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        vector<int> prev(n, 0);
        vector<int> cur(n);
        int left, up;
        for (int i = 0; i < m; i++)
        {
            fill(cur.begin(), cur.end(), 0);
            for (int j = 0; j < n; j++)
            {
                if (i == 0 && j == 0)
                {
                    cur[j] = 1;
                    continue;
                }
                up = i - 1 >= 0 ? prev[j] : 0;
                left = j - 1 >= 0 ? cur[j - 1] : 0;
                cur[j] = up + left;
            }
            swap(prev, cur);
        }
        return prev[n - 1];
    }
};
int main()
{
    Solution obj;
    assert(obj.uniquePaths(3, 2) == 3);
    assert(obj.uniquePaths(2, 4) == 4);
    return 0;
}