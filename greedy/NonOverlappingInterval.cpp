#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    bool static comp(vector<int> &a, vector<int> &b)
    {
        return a[1] < b[1];
    }

public:
    int eraseOverlapIntervals(vector<vector<int>> &intervals)
    {
        vector<vector<int>> res;
        sort(intervals.begin(), intervals.end(), comp);
        res.push_back(intervals[0]);
        int n = intervals.size(), cnt = 1, end = intervals[0][1];
        for (int i = 1; i < n; i++)
        {
            // if non overlapping interval
            if (intervals[i][0] >= end)
            {
                cnt++;
                end = intervals[i][1];
            }
        }
        return n - cnt;
    }
};
int main()
{
    Solution obj;
    return 0;
}