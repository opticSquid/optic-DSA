#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int rowWithMax1s(vector<vector<int>> &matrix, int n, int m)
    {
        int max1_count_g = 0, max1_idx = -1;
        for (int i = 0; i < n; i++)
        {
            int l = 0, r = m - 1;
            while (l <= r)
            {
                int mid = (l + r) / 2;
                // if the number found is 1
                // check in left if there is any 1 in lower indexes
                if (matrix[i][mid] > 0)
                {
                    r = mid - 1;
                }
                else
                {
                    l = mid + 1;
                }
            }
            // 'l' will contain the index of first 1
            // as individual rows are sorted if the index of 1st 1 is found
            // we can calculate the number of 1s
            int count_1_r = m - l;
            // if 2 rows have same max 1 count take the row with min row index
            if (count_1_r == max1_count_g)
            {
                max1_idx = min(max1_idx, i);
            }
            else if (count_1_r > max1_count_g)
            {
                // change the row with max1 to this row
                max1_idx = i;
                // chhange the max 1 count to this row's 1 count
                max1_count_g = count_1_r;
            }
        }
        return max1_idx;
    }
};
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> mat(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> mat[i][j];
        }
    }
    Solution obj;
    cout << obj.rowWithMax1s(mat, n, m) << endl;
    return 0;
}