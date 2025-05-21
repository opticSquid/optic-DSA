#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    int largest_area = INT_MIN;
    void largest_rectange_in_row(vector<int> &row)
    {
        int n = row.size();
        stack<int> st;
        for (int i = 0; i <= n; ++i)
        {
            while (!st.empty() && row[st.top()] > row[i])
            {
                int h = st.top();
                st.pop();
                int w = st.empty() ? i : i - st.top() - 1;
                largest_area = max(largest_area, h * w);
            }
            st.push(i);
        }
    }

public:
    int maximalRectangle(vector<vector<char>> &matrix)
    {
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> pre_computed(n, vector<int>(m));
        for (int j = 0; j < m; j++)
        {
            int sum = 0;
            for (int i = 0; i < n; i++)
            {
                if (matrix[i][j] == '1')
                {
                    sum += 1;
                }
                else if (matrix[i][j] == '0')
                {
                    sum = 0;
                }
                pre_computed[i][j] = sum;
            }
        }
        for (int i = 0; i < n; i++)
        {
            largest_rectange_in_row(pre_computed[i]);
        }
        return largest_area;
    }
};
int main()
{
    vector<vector<char>> vec = {
        {'1', '0', '1', '0', '0'},
        {'1', '0', '1', '1', '1'},
        {'1', '1', '1', '1', '1'},
        {'1', '0', '0', '1', '0'}};
    Solution obj;
    cout << obj.maximalRectangle(vec) << endl;
    return 0;
}