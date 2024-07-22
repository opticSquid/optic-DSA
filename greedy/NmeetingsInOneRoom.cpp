#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    bool static comp(vector<int> &a, vector<int> &b)
    {
        if (a[1] == b[1])
        {
            return a[2] < b[2];
        }
        else
        {
            return a[1] < b[1];
        }
    }

public:
    int maxMeetings(int start[], int end[], int n)
    {
        vector<vector<int>> calendar;
        for (int i = 0; i < n; i++)
        {
            calendar.push_back({start[i], end[i], i});
        }
        sort(calendar.begin(), calendar.end(), comp);
        int ans = 1;
        int limit = calendar[0][1];
        for (int i = 1; i < n; i++)
        {
            if (calendar[i][0] > limit)
            {
                limit = calendar[i][1];
                ans++;
            }
        }
        return ans;
    }
};
int main()
{
    Solution obj;
    int n = 6;
    int start[] = {1, 3, 0, 5, 8, 5};
    int end[] = {2, 4, 5, 7, 9, 9};
    cout << obj.maxMeetings(start, end, n) << endl;
    return 0;
}