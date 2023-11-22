#include <bits/stdc++.h>
using namespace std;
void print(vector<vector<int>> &);
vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
{
    int m = image.size(), n = image[0].size();
    int visited[m][n];
    fill(visited[0], visited[m], 0);
    vector<vector<int>> dupImage(image);
    for (int i = sr; i < m; i++)
    {
        for (int j = sc; j < n; j++)
        {
            if (image[i][j] == 0)
            {
                continue;
            }
            else
            {
                visited[i][j] = 1;
                queue<pair<int, int>> q;
                q.push({i, j});
                while (!q.empty())
                {
                    pair<int, int> node = q.front();
                    dupImage[node.first][node.second] = color;
                    q.pop();
                    // trying to confine the searh to inside the matrix
                    if (node.first - 1 >= 0 && node.first + 1 < m && node.second - 1 >= 0 && node.second + 1 < m)
                    {

                        // top
                        if (image[node.first - 1][node.second] == 1 && !visited[node.first - 1][node.second])
                        {
                            q.push({node.first - 1, node.second});
                        }
                        // right
                        if (image[node.first][node.second + 1] == 1 && !visited[node.first][node.second + 1])
                        {
                            q.push({node.first, node.second + 1});
                        }
                        // bottom
                        if (image[node.first + 1][node.second] == 1 && !visited[node.first + 1][node.second])
                        {
                            q.push({node.first + 1, node.second});
                        }
                        // left
                        if (image[node.first][node.second - 1] == 1 && !visited[node.first][node.second - 1])
                        {
                            q.push({node.first, node.second - 1});
                        }
                    }
                }
            }
        }
    }
    return dupImage;
}
int main()
{
    int m, n, sr, sc, color;
    ;
    cin >> m >> n;
    vector<vector<int>> image(m, vector(n, 0));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int x;
            cin >> x;
            image[i][j] = x;
        }
    }
    // original image
    print(image);
    cin >> sr >> sc >> color;
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