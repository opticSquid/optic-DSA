#include <bits/stdc++.h>
#include "../shared/tree-node.hpp"
using namespace std;
class Solution
{
public:
    int maxDepth(TreeNode *root)
    {
        if (root == nullptr)
        {
            return 0;
        }
        int maxD = 0;
        queue<pair<TreeNode *, int>> q;
        q.push({root, 0});
        while (!q.empty())
        {
            auto const [node, lvl] = q.front();
            q.pop();
            maxD = max(maxD, lvl);
            if (node->left != nullptr)
            {
                q.push({node->left, lvl + 1});
            }
            if (node->right != nullptr)
            {
                q.push({node->right, lvl + 1});
            }
        }
        return maxD;
    }
};
int main()
{
    Solution obj;
    return 0;
}