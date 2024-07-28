#include <bits/stdc++.h>
using namespace std;
void print(vector<vector<int>> &);
vector<vector<int>> findNearest1(vector<vector<int>> &matrix)
{
    int m = matrix.size(), n = matrix[0].size();
    int visited[m][n];
    fill(visited[0], visited[m], 0);
    vector<vector<int>> distance = vector(m, vector(n, 0));
    queue<pair<pair<int, int>, int>> q;
    // put the coordinates of all zeros in q
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] == 0)
            {
                q.push({{i, j}, 0});
                visited[i][j] = 1;
            }
        }
    }
    while (!q.empty())
    {
        pair<int, int> node = q.front().first;
        int step = q.front().second;
        // marking the distance to nearest 1 in distance array
        distance[node.first][node.second] = step;
        q.pop();
        int delRow[] = {-1, 0, +1, 0};
        int delCol[] = {0, +1, 0, -1};
        for (int i = 0; i < 4; i++)
        {
            int nrow = node.first + delRow[i];
            int ncol = node.second + delCol[i];
            bool withinBound = nrow >= 0 && nrow < m && ncol >= 0 && ncol < n;
            if (withinBound && visited[nrow][ncol] != 1 && matrix[nrow][ncol] == 1)
            {
                q.push({{nrow, ncol}, step + 1});
                visited[nrow][ncol] = 1;
            }
        }
    }
    return distance;
}
int main()
{
    // vector<vector<int>> matrix = {{0, 0, 0}, {0, 1, 0}, {1, 1, 1}};
    vector<vector<int>> matrix = {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
    cout << "original" << endl;
    print(matrix);
    vector<vector<int>> modifiedMatrix = findNearest1(matrix);
    cout << "modified" << endl;
    print(modifiedMatrix);
}
void print(vector<vector<int>> &list)
{
    cout << "....printing matrix...." << endl;
    for (auto it : list)
    {
        for (int n : it)
        {
            cout << n << " ";
        }
        cout << endl;
    }
}