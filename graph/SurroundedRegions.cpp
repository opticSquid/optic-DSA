#include <bits/stdc++.h>
using namespace std;
void print(vector<vector<char>> &);
class SurroundedRegions
{
private:
    void dfs(pair<int, int> coord, vector<vector<char>> &board, vector<vector<int>> &visited, int delRow[], int delCol[])
    {
        visited[coord.first][coord.second] = 1;
        int m = board.size(), n = board[0].size();
        for (int i = 0; i < 4; i++)
        {
            int nrow = delRow[i] + coord.first;
            int ncol = delCol[i] + coord.second;
            if (nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && !visited[nrow][ncol] && board[nrow][ncol] == 'O')
            {
                dfs({nrow, ncol}, board, visited, delRow, delCol);
            }
        }
    }

public:
    void solve(vector<vector<char>> &board)
    {
        int m = board.size(), n = board[0].size();
        int delRow[] = {-1, 0, +1, 0};
        int delCol[] = {0, +1, 0, -1};
        vector<vector<int>> visited(m, vector<int>(n, 0));
        // check for '0' groups connected to boundaries
        for (int i = 0; i < max(m, n); i++)
        {
            if (i < n)
            {
                // first row
                if (!visited[0][i] && board[0][i] == 'O')
                {

                    dfs({0, i}, board, visited, delRow, delCol);
                }
                // last row
                if (!visited[m - 1][i] && board[m - 1][i] == 'O')
                {
                    dfs({m - 1, i}, board, visited, delRow, delCol);
                }
            }
            if (i < m)
            {
                // first col
                if (!visited[i][0] && board[i][0] == 'O')
                {
                    dfs({i, 0}, board, visited, delRow, delCol);
                }
                // last col
                if (!visited[i][n - 1] && board[i][n - 1] == 'O')
                {
                    dfs({i, n - 1}, board, visited, delRow, delCol);
                }
            }
        }
        // Here all the '0' groups connected to boundaries will have been visited
        // so, only thr '0' groups not connected to boundaries will not have been visited
        // so, they definately would have been surrounded by 'X'.
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (!visited[i][j] && board[i][j] == 'O')
                {
                    board[i][j] = 'X';
                }
            }
        }
    }
};
int main()
{
    vector<vector<char>> mat{{'X', 'O', 'X', 'O', 'X', 'O'}, {'O', 'X', 'O', 'X', 'O', 'X'}, {'X', 'O', 'X', 'O', 'X', 'O'}, {'O', 'X', 'O', 'X', 'O', 'X'}};
    // vector<vector<char>> mat{{'X', 'X', 'X', 'X'}, {'O', 'X', 'O', 'X'}, {'X', 'O', 'O', 'X'}, {'X', 'X', 'X', 'X'}};
    cout << "original" << endl;
    print(mat);
    SurroundedRegions ob;
    // n = 5, m = 4
    ob.solve(mat);
    cout << "modified" << endl;
    print(mat);
    return 0;
}
void print(vector<vector<char>> &board)
{
    int m = board.size(), n = board[0].size();
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }
}