#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int findCenter(vector<vector<int>> &edges)
    {
        int n = edges.size();
        unordered_map<int, int> hash;
        for (int i = 0; i < n; i++)
        {
            hash[edges[i][0]]++;
            hash[edges[i][1]]++;
        }
        for (auto i : hash)
        {
            if (i.second == n)
            {
                return i.first;
            }
        }
        return -1;
    }
};
int main()
{
    vector<vector<int>> edges = {{1, 2}, {2, 3}, {4, 2}};
    Solution obj;
    cout << obj.findCenter(edges) << endl;
    return 0;
}