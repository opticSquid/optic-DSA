#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    int oneD_index_2_twoD_index_converter(vector<vector<int>> &mat, int &col_size, int &virtual_indx)
    {
        int real_row = virtual_indx / col_size;
        int real_col = virtual_indx % col_size;
        return mat[real_row][real_col];
    }

public:
    bool searchMatric_best_impl(vector<vector<int>> &mat, int target)
    {
        int n = mat.size(), m = mat[0].size();
        int l = 0, r = (n * m) - 1;
        while (l <= r)
        {
            int mid = (l + r) / 2;
            if (oneD_index_2_twoD_index_converter(mat, m, mid) == target)
            {
                return true;
            }
            else if (oneD_index_2_twoD_index_converter(mat, m, mid) < target)
            {
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }
        return false;
    }
    bool searchMatrix_better_impl(vector<vector<int>> &mat, int target)
    {
        int n = mat.size(), m = mat[0].size();
        int low = 0, high = n - 1;
        while (low <= high)
        {
            int mid_row = (low + high) / 2;
            // identify the row in which the target element can lie
            // for this check the first and last element of the row
            // to check its range and compare it to target
            // if found do a simple binary search in that row.
            if (mat[mid_row][0] <= target && target <= mat[mid_row][m - 1])
            {
                int left = 0, right = m - 1;
                while (left <= right)
                {
                    int mid = (left + right) / 2;
                    if (mat[mid_row][mid] == target)
                    {
                        return true;
                    }
                    else if (mat[mid_row][mid] < target)
                    {
                        left = mid + 1;
                    }
                    else
                    {
                        right = mid - 1;
                    }
                }
                // element is with the range of the current row
                // but not present in the row.
                return false;
            }
            if (target < mat[mid_row][0])
            {
                high = mid_row - 1;
            }
            else if (target > mat[mid_row][m - 1])
            {
                low = mid_row + 1;
            }
        }
        // if the element is not within the range of any row
        // and not found in the array
        return false;
    }
};
int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> mat(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> mat[i][j];
        }
    }
    Solution obj;
    cout << obj.searchMatrix_better_impl(mat, k) << endl;
    cout << obj.searchMatric_best_impl(mat, k) << endl;
    return 0;
}