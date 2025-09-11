#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<int> adjList[numCourses];
        for (const auto &p : prerequisites)
        {
            adjList[p[1]].push_back(p[0]);
        }

        vector<int> inDegree(numCourses, 0);
        for (int i = 0; i < numCourses; i++)
        {
            for (const auto &it : adjList[i])
            {
                inDegree[it]++;
            }
        }

        queue<int> q;
        for (int i = 0; i < numCourses; i++)
        {
            if (inDegree[i] == 0)
            {
                q.push(i);
            }
        }
        vector<int> topo;
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            topo.push_back(node);
            for (const auto &it : adjList[node])
            {
                inDegree[it]--;
                if (inDegree[it] == 0)
                {
                    q.push(it);
                }
            }
        }

        if (topo.size() == numCourses)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};
int main()
{
    Solution obj;
    return 0;
}