#include <bits/stdc++.h>

using namespace std;

int solve(int n, int w)
{
    return (w - 1) * (n / w) + (n % w);
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
        int n, w;
        cin >> n >> w;
        cout << solve(n, w) << "\n";
    }
    cout << endl;
    return 0;
}
