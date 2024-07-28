#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
    {
        vector<vector<int>> res;
        int n = intervals.size(), i = 0;
        // left half
        // ending part of existing intervals is less than
        // starting part of new interval
        while (i < n && intervals[i][1] < newInterval[0])
        {
            res.push_back(intervals[i]);
            i++;
        }
        // overlapping part
        // starting part of existing interval is less than
        // ending part of new interval
        while (i < n && intervals[i][0] <= newInterval[1])
        {
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            i++;
        }
        res.push_back(newInterval);
        // right part
        // for all the rest part
        while (i < n)
        {
            res.push_back(intervals[i]);
            i++;
        }
        return res;
    }
};
int main()
{
    Solution obj;
    return 0;
}