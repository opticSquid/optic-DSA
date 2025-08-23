#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    vector<int> delrow = {-1, 0, +1, 0};
    vector<int> delcol = {0, +1, 0, -1};
    bool dfs(vector<vector<char>> &board, vector<vector<bool>> &visited, pair<int, int> pos, const int m, const int n, string &word, int k)
    {
        if (k == word.size())
        {
            return true;
        }
        // Boundary checks and character match
        if (pos.first < 0 || pos.first >= m || pos.second < 0 || pos.second >= n || visited[pos.first][pos.second] || board[pos.first][pos.second] != word[k])
        {
            return false;
        }
        visited[pos.first][pos.second] = true;
        bool found = false;
        for (int i = 0; i < 4; i++)
        {
            int nrow = pos.first + delrow[i];
            int ncol = pos.second + delcol[i];
            found = found || dfs(board, visited, {nrow, ncol}, m, n, word, k + 1);
        }
        visited[pos.first][pos.second] = false;
        return found;
    }

public:
    bool exist(vector<vector<char>> &board, string word)
    {
        if (word.empty())
            return true;
        if (board.empty() || board[0].empty())
            return false;
        const int m = board.size(), n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for (int row = 0; row < m; row++)
        {
            for (int col = 0; col < n; col++)
            {
                if (board[row][col] == word[0])
                {
                    if (dfs(board, visited, {row, col}, m, n, word, 0))
                    {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};
int main()
{
    vector<vector<char>> vec = {{'A', 'B', 'C', 'E'},
                                {'S', 'F', 'E', 'S'},
                                {'A', 'D', 'E', 'E'}};
    string word = "ABCESEEEFS";
    Solution obj;
    cout << obj.exist(vec, word) << endl;
    return 0;
}