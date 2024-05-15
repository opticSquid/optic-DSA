#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    int find_max_in_column(vector<vector<int>> &mat, int &n, int &col)
    {
        int max = INT_MIN;
        int max_index = 0;
        for (int i = 0; i < n; i++)
        {
            if (mat[i][col] > mat[max_index][col])
            {
                max = mat[i][col];
                max_index = i;
            }
        }
        return max_index;
    }

public:
    vector<int> findPeakGrid(vector<vector<int>> &mat)
    {
        int n = mat.size(), m = mat[0].size();
        int low = 0, high = m - 1;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            int max_in_col = find_max_in_column(mat, n, mid);
            int left = mid - 1 >= 0 ? mat[max_in_col][mid - 1] : -1;
            int right = mid + 1 < m ? mat[max_in_col][mid + 1] : -1;
            if (left < mat[max_in_col][mid] && mat[max_in_col][mid] > right)
            {
                return {max_in_col, mid};
            }
            else if (left > mat[max_in_col][mid])
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return {-1, -1};
    }
};
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> mat(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> mat[i][j];
        }
    }
    Solution obj;
    cout << obj.findPeakGrid(mat) << endl;
    return 0;
}