#include <bits/stdc++.h>

using namespace std;

int get_branch_root(int i)
{
    while (i > 0 && i % 2 == 0)
    {
        i /= 2;
    }
    return i;
}

bool solve(vector<int> &v)
{
    for (int i = 1; i < v.size(); i++)
    {
        int cp = i;
        int tp = v[i];
        if (get_branch_root(cp) != get_branch_root(tp))
        {
            return false;
        }
    }
    return true;
}

int main()
{
    // Fast I/O
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // For problems with multiple test cases
    int t = 1;
    // Uncomment the next line if there are multiple test cases
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v(n + 1);
        for (int i = 1; i <= n; i++)
        {
            cin >> v[i];
        }
        bool res = solve(v);
        if (res)
        {
            cout << "YES" << "\n";
        }
        else
        {
            cout << "NO" << "\n";
        }
    }
    cout << endl;
    return 0;
}
