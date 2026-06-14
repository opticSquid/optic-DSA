#include <bits/stdc++.h>
#include "../shared/tree-node.hpp"
using namespace std;
class Solution
{
public:
    TreeNode *searchBST(TreeNode *root, int val)
    {
        TreeNode *node = root;
        while (node != nullptr)
        {
            if (node->val == val)
            {
                return node;
            }
            else if (val < node->val)
            {
                node = node->left;
            }
            else
            {
                node = node->right;
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