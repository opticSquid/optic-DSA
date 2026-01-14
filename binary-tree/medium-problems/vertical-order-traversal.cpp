#include <bits/stdc++.h>
#include "./shared/tree-node.hpp"
using namespace std;
class Solution
{
public:
    vector<vector<int>> verticalTraversal(TreeNode *root)
    {
        if (root == nullptr)
        {
            return {};
        }
        map<int, map<int, multiset<int>>> db;

        queue<pair<TreeNode *, pair<int, int>>> q;

        q.push({root, {0, 0}});

        while (!q.empty())
        {
            auto p = q.front();
            q.pop();
            TreeNode *temp = p.first;
            auto [x, y] = p.second;

            db[x][y].insert(temp->val);

            if (temp->left != nullptr)
            {
                q.push({temp->left, {x - 1, y + 1}});
            }
            if (temp->right != nullptr)
            {
                q.push({temp->right, {x + 1, y + 1}});
            }
        }
        vector<vector<int>> ans;
        for (auto p : db)
        {
            vector<int> col;
            for (auto q : p.second)
            {
                col.insert(col.end(), q.second.begin(), q.second.end());
            }
            ans.push_back(col);
        }
        return ans;
    }
};
int main()
{
    Solution obj;
    return 0;
}