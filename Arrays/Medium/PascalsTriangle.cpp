#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    unordered_map<int, int> mp;
    int factorial(int n)
    {
        if (mp.find(n) != mp.end())
        {
            return mp[n];
        }
        else
        {
            if (n <= 0)
            {
                mp.insert({n, 1});
                return 1;
            }
            int res = n;
            res *= factorial(n - 1);
            mp.insert({n, res});
            return res;
        }
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
                row.push_back(factorial(r - 1) / (factorial(c - 1) * factorial((r - 1) - (c - 1))));
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