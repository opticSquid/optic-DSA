#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int earliestTime(vector<vector<int>> &tasks)
    {
        int minTime = INT_MAX;
        for (const vector<int> &t : tasks)
        {
            minTime = min(minTime, t[0] + t[1]);
        }
        return minTime;
    }
};
int main()
{
    Solution obj;
    return 0;
}