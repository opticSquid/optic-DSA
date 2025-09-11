#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<int> adjList[numCourses];
        vector<int> indegree(numCourses, 0);
        for (const auto &prq : prerequisites)
        {
            adjList[prq[1]].push_back(prq[0]);
            indegree[prq[0]]++;
        }
        queue<int> q;
        for (int i = 0; i < numCourses; i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }
        int cnt = 0;
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            cnt++;
            for (int i : adjList[node])
            {
                indegree[i]--;
                if (indegree[i] == 0)
                {
                    q.push(i);
                }
            }
        }
        return cnt == numCourses;
    }
};
int main()
{
    Solution obj;
    return 0;
}