#include <bits/stdc++.h>
using namespace std;
struct Job
{
    int id;     // Job Id
    int dead;   // Deadline of job
    int profit; // Profit if job is over before or on deadline
};
class Solution
{
private:
    bool static comp(Job a, Job b)
    {
        return a.profit > b.profit;
    }

public:
    // Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n)
    {
        sort(arr, arr + n, comp);
        int maxD = arr[0].dead;
        for (int i = 0; i < n; i++)
        {
            maxD = max(maxD, arr[i].dead);
        }
        int time[maxD + 1];
        memset(time, -1, sizeof time);
        int taskCount = 0, maxProfit = 0;
        for (int i = 0; i < n; i++)
        {
            // check if a task already exists in that day
            // check if it can be performed earlier
            // other wise perform the task on the day of deadline
            for (int j = arr[i].dead; j > 0; j--)
            {
                if (time[j] == -1)
                {
                    time[j] = i;
                    taskCount++;
                    maxProfit += arr[i].profit;
                    break;
                }
            }
        }
        return {taskCount, maxProfit};
    }
};
int main()
{
    int n;
    cin >> n;
    Job arr[n];
    for (int i = 0; i < n; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        arr[i] = {a, b, c};
    }
    Solution obj;
    for (auto it : obj.JobScheduling(arr, n))
    {
        cout << it << " ";
    }
    return 0;
}