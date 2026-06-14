#include <bits/stdc++.h>
#include "../shared/tree-node.hpp"
using namespace std;
class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        while (root != nullptr)
        {
            if (p->val < root->val && q->val < root->val)
            {
                root = root->left;
            }
            else if (p->val > root->val && q->val > root->val)
            {
                root = root->right;
            }
            else
            {
                return root;
            }
        }
        return nullptr;
    }
};
int main()
{
    Solution obj;
    return 0;
}