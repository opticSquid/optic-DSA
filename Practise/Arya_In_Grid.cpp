#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long n, m, x0, y0, l;
        cin >> n >> m >> x0 >> y0 >> l;
        if (l == 1)
        {
            cout << n * m << endl;
            continue;
        }
        vector<vector<int>> matrix(n, vector(m, 0));
        queue<pair<long, long>> track;
        track.push({x0 - 1, y0 - 1});
        long r[] = {-l, 0, +l, 0};
        long c[] = {0, +l, 0, -l};
        int counter = 0;
        while (!track.empty())
        {
            pair<int, int> node = track.front();
            // if node was already visited in any other path
            if (matrix[node.first][node.second])
            {
                track.pop();
                continue;
            }
            track.pop();
            matrix[node.first][node.second] = 1;
            counter++;
            for (int i = 0; i < 4; i++)
            {
                long long nr = node.first + r[i];
                long long nc = node.second + c[i];
                if (nr >= 0 && nr < n && nc >= 0 && nc < m && !matrix[nr][nc])
                {
                    track.push({nr, nc});
                }
            }
        }
        cout << counter << endl;
    }
    return 0;
}