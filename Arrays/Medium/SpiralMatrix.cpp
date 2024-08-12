#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        vector<int> ans;
        int n = matrix.size(), m = matrix[0].size();
        int top = 0, right = m - 1, bottom = n - 1, left = 0;
        // move through the whole maatrix until ends cross each other
        while (top <= bottom && left <= right)
        {
            // move from left to right
            for (int i = left; i <= right; i++)
            {
                ans.push_back(matrix[top][i]);
            }
            // top moves 1 row down
            top++;
            // move from top to bottom
            for (int i = top; i <= bottom; i++)
            {
                ans.push_back(matrix[i][right]);
            }
            // move right 1 column left
            right--;

            // for 1 row matrix if it was traversed earlier we would not like to do it again
            if (top <= bottom)
            {
                // moving from right to left
                for (int i = right; i >= left; i--)
                {
                    ans.push_back(matrix[bottom][i]);
                }
                // move bottom 1 row up
                bottom--;
            }
            // for 1 column matrix if it was traversed earlier we would not like to do it again
            if (left <= right)
            {
                // moving from bottom to top;
                for (int i = bottom; i >= top; i--)
                {
                    ans.push_back(matrix[i][left]);
                }
                // moving left 1 column to right
                left++;
            }
        }
        return ans;
    }
};
int main()
{
    Solution obj;
    return 0;
}