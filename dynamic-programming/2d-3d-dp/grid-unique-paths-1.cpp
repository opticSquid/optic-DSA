#include <bits/stdc++.h>
#include <cassert>
using namespace std;
class Solution
{

public:
    int uniquePaths(int m, int n)
    {
        // basically it is solving
        // (m+n-2)!/((m-1)!*(n-1)!)
        int ans = 1;
        for (int i = m + n - 2, j = 1; i >= max(m, n); i--, j++)
        {
            ans = (ans * i) / j;
        }
        return ans;
    }
};
int main()
{
    Solution obj;
    obj.uniquePaths(1, 2);
    assert(obj.uniquePaths(3, 2) == 3);
    assert(obj.uniquePaths(2, 4) == 4);
    return 0;
}