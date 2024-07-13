#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int findContentChildren(vector<int> &g, vector<int> &s)
    {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int n = g.size(), m = s.size();
        int child, cookie = 0;
        while (child < n && cookie < m)
        {
            if (g[child] <= s[cookie])
            {
                child++;
            }
            cookie++;
        }
        return child;
    }
};
int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> g(n), s(m);

    for (int i = 0; i < n; i++)
    {
        cin >> g[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> s[i];
    }
    Solution obj;
    cout << obj.findContentChildren(g, s) << endl;
    return 0;
}