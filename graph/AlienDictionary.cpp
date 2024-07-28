#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    vector<char> topoSort(int k, vector<int> graph[])
    {
        int indegree[k] = {0};
        for (int i = 0; i < k; i++)
        {
            for (int j : graph[i])
            {
                indegree[j]++;
            }
        }
        stack<int> s;
        for (int i = 0; i < k; i++)
        {
            if (indegree[i] == 0)
            {
                s.push(i);
            }
        }
        vector<char> res;
        while (!s.empty())
        {
            int node = s.top();
            s.pop();
            res.push_back(node + 'a');
            for (int it : graph[node])
            {
                indegree[it]--;
                if (indegree[it] == 0)
                {
                    s.push(it);
                }
            }
        }
        return res;
    }

public:
    vector<char> findOrder(int n, int k, string dict[])
    {
        vector<int> graph[k];
        for (int i = 0; i < n - 1; i++)
        {
            string s1 = dict[i];
            string s2 = dict[i + 1];
            for (int j = 0; j < min(s1.size(), s2.size()); j++)
            {
                if (s1[j] != s2[j])
                {
                    graph[s1[j] - 'a'].push_back(s2[j] - 'a');
                    break;
                }
            }
        }
        return topoSort(k, graph);
    }
};
int main()
{
    int n = 5, k = 4;
    string dict[] = {"baa", "abcd", "abca", "cab", "cad"};
    Solution obj;
    vector<char> result = obj.findOrder(n, k, dict);
    for (char i : result)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}