#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    // ! don't use recursion for dfs in this case because
    // ! then you need to keep a track of another variable
    // ! that would know if one of the recursive calls returned false
    // ! if 1 recursion returned false still other recursions will take place
    // ! which makes it inefficient in this case
    // ! because once you get false you no longer need to do DFS.
    bool dfs(int firstNode, int firstNodeColor, vector<vector<int>> &graph, int colorArray[])
    {
        stack<pair<int, int>> s;
        s.push({firstNode, firstNodeColor});
        while (!s.empty())
        {
            int node = s.top().first;
            int nodeColor = s.top().second;
            colorArray[node] = nodeColor;
            s.pop();
            for (int it : graph[node])
            {
                // un-colored node
                if (colorArray[it] == -1)
                {
                    s.push({it, !nodeColor});
                }
                // check if the node color matches with its neighbour's color
                else if (colorArray[it] == nodeColor)
                {
                    return false;
                }
            }
        }
        return true;
    }

public:
    bool isBipartite(vector<vector<int>> &graph)
    {
        int n = graph.size();
        // color array has 3 possible values
        // -1: un-coloured
        // 0: group A
        // 1: group B
        int colorArray[n];
        memset(colorArray, -1, n * sizeof(int));

        for (int i = 0; i < n; i++)
        {
            // used in case of disconnected components
            // check for the unvisited node in array
            if (colorArray[i] == -1)
            {
                if (dfs(i, 0, graph, colorArray) == false)
                {
                    return false;
                }
            }
        }
        return true;
    }
};

int main()
{
    // try with
    //[[2,3,5,6,7,8,9],[2,3,4,5,6,7,8,9],[0,1,3,4,5,6,7,8,9],[0,1,2,4,5,6,7,8,9],[1,2,3,6,9],[0,1,2,3,7,8,9],[0,1,2,3,4,7,8,9],[0,1,2,3,5,6,8,9],[0,1,2,3,5,6,7],[0,1,2,3,4,5,6,7]]
    // this output should be false but true is coming
    vector<vector<int>> graph = {{2, 3, 5, 6, 7, 8, 9},
                                 {2, 3, 4, 5, 6, 7, 8, 9},
                                 {0, 1, 3, 4, 5, 6, 7, 8, 9},
                                 {0, 1, 2, 4, 5, 6, 7, 8, 9},
                                 {1, 2, 3, 6, 9},
                                 {0, 1, 2, 3, 7, 8, 9},
                                 {0, 1, 2, 3, 4, 7, 8, 9},
                                 {0, 1, 2, 3, 5, 6, 8, 9},
                                 {0, 1, 2, 3, 5, 6, 7},
                                 {0, 1, 2, 3, 4, 5, 6, 7}};
    // vector<vector<int>> graph = {{1, 3},
    //                              {0, 2},
    //                              {1, 3},
    //                              {0, 2}};
    Solution obj;
    cout << obj.isBipartite(graph) << endl;
}