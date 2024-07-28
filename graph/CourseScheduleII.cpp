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
                true;
            }
        }
        pathTravelled.push_back(node);
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
                }
            }
        }
        return pathTravelled;
    }
};
class OptimizedSolution
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

    bool dfsCheck(int node, vector<vector<int>> &adjList, bitset<2> tracked[], vector<int> &pathTravelled)
    {
        // visited
        tracked[node].set(1, 1);
        // pathVisited
        tracked[node].set(0, 1);
        // traverse for adjacent nodes
        for (auto it : adjList[node])
        {
            // when the node is not visited
            if (tracked[it].count() == 0)
            {
                if (dfsCheck(it, adjList, tracked, pathTravelled) == true)
                    return true;
            }
            // node is visited but and also path visited
            else if (tracked[it].count() == 2)
            {
                return true;
            }
        }
        pathTravelled.push_back(node);
        // unsetting path visited and making it 0
        tracked[node].set(0, 0);
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
            // initially this array has 00 value for all indexes
            // this array can store 3 values
            // 0 = in binary 00. first 0 will show not visited, 2nd 0 will show not pathVisited
            // 2 = in binary 10. first 1 will show visited and 2nd 0 will show not pathVisited
            // 3 = in binary 11. first 1 will shoe visited, 2nd 1 will show pathVisited
            //
            bitset<2> tracked[numCourses];
            vector<vector<int>> adjList(numCourses, vector<int>({}));
            convertToAdjList(numCourses, prerequisites, adjList);
            for (int i = 0; i < numCourses; i++)
            {
                if (tracked[i].count() == 0)
                {
                    if (dfsCheck(i, adjList, tracked, pathTravelled) == true)
                    {
                        return {};
                    }
                }
            }
        }
        return pathTravelled;
    }
};
int main()
{
    int numCourses = 2;
    vector<vector<int>> prerequisites = {{1, 0}};
    OptimizedSolution obj;
    vector<int> result = obj.findOrder(numCourses, prerequisites);
    for (int r : result)
    {
        cout << r << " ";
    }
    return 0;
}