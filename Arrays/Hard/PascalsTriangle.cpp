#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    int short_nCr(int n, int r)
    {
        long long res = 1;
        for (int i = 0; i < r; i++)
        {
            res *= n - i;
            res /= i + 1;
        }
        return res;
    }

public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> ans;
        for (int r = 1; r <= numRows; r++)
        {
            vector<int> row;
            for (int c = 1; c <= r; c++)
            {
                row.push_back(short_nCr(r - 1, c - 1));
            }
            ans.push_back(row);
        }
        return ans;
    }
};
int main()
{
    int numRows;
    cout << "Enter the number of rows of pascal's triangle you want to print? \n";
    cin >> numRows;
    Solution obj;
    for (vector<int> row : obj.generate(numRows))
    {
        cout << "[";
        for (int i : row)
        {
            cout << i << ", ";
        }
        cout << "]\n";
    }
}