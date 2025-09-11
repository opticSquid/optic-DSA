#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maxProfit(int n, vector<int> &present, vector<int> &future, vector<vector<int>> &hierarchy, int budget)
    {
        bool visited[n];
        memset(visited, false, n * sizeof(bool));
        queue<int> q;
        q.push(0);
        visited[0] = true;
        int profit = 0;
        profit += future[0] - present[0];
        while (!q.empty())
        {
            int boss = q.front();
            q.pop();
            for (int emp = 0; emp < n; emp++)
            {
                visited[emp] = true;
                profit += future[]
            }
        }
    }
};
int main()
{
    Solution obj;
    return 0;
}