#include <bits/stdc++.h>
using namespace std;
class DisjointSet
{
private:
    vector<int> rank, parent;

public:
    DisjointSet(int n)
    {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
        }
    }

    int findUPar(int node)
    {
        if (parent[node] == node)
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v)
    {
        int up_u = findUPar(u);
        int up_v = findUPar(v);
        if (up_u == up_v)
            return;
        else if (rank[up_u] < rank[up_v])
        {
            parent[up_u] = up_v;
        }
        else if (rank[up_u] > rank[up_v])
        {
            parent[up_v] = up_u;
        }
        else if (rank[up_u] == rank[up_v])
        {
            parent[up_u] = up_v;
            rank[up_v]++;
        }
    }
};
class Solution
{
public:
    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts)
    {
        int n = accounts.size();
        sort(accounts.begin(), accounts.end());
        DisjointSet ds(n);
        // {email, index}
        unordered_map<string, int> mapMailNode;
        for (int i = 0; i < n; i++)
        {
            for (int j = 1; j < accounts[i].size(); j++)
            {
                if (mapMailNode.find(accounts[i][j]) == mapMailNode.end())
                {
                    mapMailNode[accounts[i][j]] = i;
                }
                else
                {
                    ds.unionByRank(i, mapMailNode[accounts[i][j]]);
                }
            }
        }
        // [{email1, email2}, {email3}, {email4, email5, email6}, ...]
        // [      up_1,         up_2,             up_3,           ...]
        vector<string> mergedMail[n];
        for (auto it : mapMailNode)
        {
            string mail = it.first;
            int node = ds.findUPar(it.second);
            mergedMail[node].push_back(mail);
        }

        vector<vector<string>> ans;
        for (int i = 0; i < n; i++)
        {
            if (mergedMail[i].size() == 0)
                continue;
            sort(mergedMail[i].begin(), mergedMail[i].end());
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            for (auto it : mergedMail[i])
            {
                temp.push_back(it);
            }
            ans.push_back(temp);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};
int main()
{
    vector<vector<string>> accounts = {{"John", "j1@com", "j2@com", "j3@com"},
                                       {"John", "j4@com"},
                                       {"Raj", "r1@com", "r2@com"},
                                       {"John", "j1@com", "j5@com"},
                                       {"Raj", "r2@com", "r3@com"},
                                       {"Mary", "m1@com"}};

    Solution obj;
    vector<vector<string>> ans = obj.accountsMerge(accounts);
    for (auto acc : ans)
    {
        cout << acc[0] << ":";
        int size = acc.size();
        for (int i = 1; i < size; i++)
        {
            cout << acc[i] << " ";
        }
        cout << endl;
    }
    return 0;
}