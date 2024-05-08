#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool searchElement(vector<vector<int>> &mat, int k)
    {
        int n = mat.size(), m = mat[0].size();
        int row = 0, col = m - 1;
        // traverse the matrix from 0, m-1
        while (row < n && col >= 0)
        {
            if (mat[row][col] == k)
                return true;
            if (mat[row][col] < k)
                row++;
            else
                col--;
        }
        return false;
    }
};
int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> matrix(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> matrix[i][j];
        }
    }
    Solution obj;
    cout << obj.searchElement(matrix, k) << endl;
    return 0;
}