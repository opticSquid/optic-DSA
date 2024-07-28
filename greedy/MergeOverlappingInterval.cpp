#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        // sort the intervals
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> res;
        int n = intervals.size();
        for (int i = 0; i < n; i++)
        {
            // if the current interval does not
            // lie in the last interval:
            // checks if res is empty or current interval's starting is greater than
            // the ending of the previously stored interval.
            // this shows two intervals are non overlapping
            if (res.empty() || intervals[i][0] > res.back()[1])
            {
                res.push_back(intervals[i]);
            }
            // if the current interval
            // lies in the last interval:
            // these work for all the intervals that overlap
            else
            {
                res.back()[1] = max(res.back()[1], intervals[i][1]);
            }
        }
        return res;
    }
};
int main()
{
    Solution obj;
    return 0;
}