#include <bits/stdc++.h>
using namespace std;
void print(vector<vector<int>> &);
vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
{
    int m = image.size(), n = image[0].size();
    int visited[m][n];
    fill(visited[0], visited[m], 0);
    vector<vector<int>> dupImage(image);
    queue<pair<int, int>> q;
    int startingColor = image[sr][sc];
    q.push({sr, sc});
    while (!q.empty())
    {
        pair<int, int> node = q.front();
        // for a vertex which is connnected to 2 nodes and has been visited in the process
        if (visited[node.first][node.second] == 1)
        {
            q.pop();
            continue;
        }
        visited[node.first][node.second] = 1;
        dupImage[node.first][node.second] = color;
        q.pop();
        // top
        // check the confine first
        if (node.first - 1 >= 0)
        {
            if (image[node.first - 1][node.second] == startingColor && !visited[node.first - 1][node.second])
            {
                q.push({node.first - 1, node.second});
            }
        }
        // right
        // check the confine first
        if (node.second + 1 < n)
        {
            if (image[node.first][node.second + 1] == startingColor && !visited[node.first][node.second + 1])
            {
                q.push({node.first, node.second + 1});
            }
        }
        // bottom
        // check the confine first
        if (node.first + 1 < m)
        {
            if (image[node.first + 1][node.second] == startingColor && !visited[node.first + 1][node.second])
            {
                q.push({node.first + 1, node.second});
            }
        }

        // left
        // check the confine first
        if (node.second - 1 >= 0)
        {
            if (image[node.first][node.second - 1] == startingColor && !visited[node.first][node.second - 1])
            {
                q.push({node.first, node.second - 1});
            }
        }
    }
    return dupImage;
}
int main()
{
    int m, n, sr, sc, color;
    // cin >> m >> n;
    // vector<vector<int>> image(m, vector(n, 0));
    // for (int i = 0; i < m; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         int x;
    //         cin >> x;
    //         image[i][j] = x;
    //     }
    // }
    // original image
    m = 4, n = 5, sr = 0, sc = 0, color = 3;
    vector<vector<int>> image = {{0, 0, 1, 0, 0},
                                 {0, 1, 1, 0, 1},
                                 {0, 1, 1, 1, 1},
                                 {1, 0, 1, 0, 0}};
    // cin >> sr >> sc >> color;
    vector<vector<int>> floodFilledImage;
    floodFilledImage = floodFill(image, sr, sc, color);
    print(floodFilledImage);
    return 0;
}
void print(vector<vector<int>> &image)
{
    cout << "printing..." << endl;
    for (vector<int> rows : image)
    {
        for (int pixel : rows)
        {
            cout << pixel << " ";
        }
        cout << endl;
    }
}