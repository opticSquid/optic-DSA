#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<int>> construct2DArray(vector<int> &original, int m, int n)
    {
        vector<vector<int>> ans(m, vector<int>(n));
        for (int i = 0; i < original.size(); i++)
        {
            int row = i / n, col = i % n;
            ans[row][col] = original[i];
        }
        return ans;
    }
};
int main()
{
    int n;
    cin >> n;
    vector<int> inp(n);
    for (int i = 0; i < n; i++)
    {
        cin >> inp[i];
    }
    int r, c;
    cin >> r >> c;
    Solution obj;
    for (vector<int> row : obj.construct2DArray(inp, r, c))
    {
        cout << "[ ";
        for (int i : row)
        {
            cout << i << ", ";
        }
        cout << "]" << endl;
    }
    return 0;
}