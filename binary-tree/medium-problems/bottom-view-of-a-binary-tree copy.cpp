#include <bits/stdc++.h>
#include "./shared/tree-node.hpp";
using namespace std;
using Node = TreeNode;
class Solution
{
public:
    vector<int> bottomView(Node *root)
    {
        if (root == nullptr)
        {
            return {};
        }
        map<int, int> mp;
        queue<pair<Node *, int>> q;
        q.push({root, 0});
        while (!q.empty())
        {
            auto [p, lvl] = q.front();
            q.pop();
            mp[lvl] = p->val;

            if (p->left != nullptr)
            {
                q.push({p->left, lvl - 1});
            }
            if (p->right != nullptr)
            {
                q.push({p->right, lvl + 1});
            }
        }
        vector<int> ans;
        for (const auto &i : mp)
        {
            ans.push_back(i.second);
        }
        return ans;
    };
};
int main()
{
    Solution obj;
    return 0;
}