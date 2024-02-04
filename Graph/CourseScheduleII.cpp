#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    void convertToAdjList(int numCourses, vector<vector<int>> &prerequisites, vector<vector<int>> &adjList)
    {
        for (vector<int> row : prerequisites)
        {
            int course = row[0];
            for (int i = 1; i < row.size(); i++)
            {
                adjList[course].push_back(row[i]);
            }
        }
    }
    bool dfsCheck(int node, vector<vector<int>> &adjList, int vis[], int pathVis[], vector<int> &pathTravelled)
    {
        vis[node] = 1;
        pathVis[node] = 1;
        // traverse for adjacent nodes
        for (auto it : adjList[node])
        {
            // when the node is not visited
            if (!vis[it])
            {
                if (dfsCheck(it, adjList, vis, pathVis, pathTravelled) == true)
                    return true;
            }
            else if (pathVis[it])
            {
                // if (!pathVis[it])
                // {
                //     pathTravelled.push_back(it);
                // }
                // else
                // {
                return true;
                // }
            }
        }
        pathTravelled.push_back(node);
        // pathTravelled.push_back(node);
        pathVis[node] = 0;
        return false;
    }

public:
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<int> pathTravelled;
        if (prerequisites.empty())
        {
            for (int i = 0; i < numCourses; i++)
            {
                pathTravelled.push_back(i);
            }
        }
        else
        {
            int visited[numCourses];
            memset(visited, 0, numCourses * sizeof(int));
            int pathVisited[numCourses];
            memset(pathVisited, 0, numCourses * sizeof(int));
            vector<vector<int>> adjList(numCourses, vector<int>({}));
            convertToAdjList(numCourses, prerequisites, adjList);

            for (int i = 0; i < numCourses; i++)
            {
                if (!visited[i])
                {
                    if (dfsCheck(i, adjList, visited, pathVisited, pathTravelled) == true)
                    {
                        return {};
                    }
                    // just in case
                    // all node was not visited in this path
                    // else if (numCourses != pathTravelled.size())
                    // {
                    //     pathTravelled.clear();
                    // }
                }
            }
        }
        return pathTravelled;
    }
};
int main()
{
    int numCourses = 2;
    vector<vector<int>> prerequisites = {{0, 1}};
    Solution obj;
    vector<int> result = obj.findOrder(numCourses, prerequisites);
    for (int r : result)
    {
        cout << r << " ";
    }
    return 0;
}