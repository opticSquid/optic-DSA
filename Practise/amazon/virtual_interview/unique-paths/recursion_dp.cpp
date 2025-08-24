#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    int travel(int i, int j, vector<vector<int>> &paths)
    {
        if (i == 0 && j == 0)
        {
            return 1;
        }
        else if (i < 0 || j < 0)
        {
            return 0;
        }
        else if (paths[i][j] != -1)
        {
            return paths[i][j];
        }
        int u = travel(i - 1, j, paths);
        int l = travel(i, j - 1, paths);
        return paths[i][j] = u + l;
    }

public:
    int uniquePaths(int m, int n)
    {
        vector<vector<int>> paths(m, vector<int>(n, -1));
        return travel(m - 1, n - 1, paths);
    }
};
int main()
{
    int m, n;
    cin >> m >> n;
    Solution obj;
    cout << obj.uniquePaths(m, n) << endl;
    return 0;
}