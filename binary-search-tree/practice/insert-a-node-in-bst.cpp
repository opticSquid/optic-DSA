#include <bits/stdc++.h>
#include "../shared/tree-node.hpp"
using namespace std;
class Solution
{
public:
    TreeNode *insertIntoBST(TreeNode *root, int val)
    {
        if (root == nullptr)
        {
            return new TreeNode(val);
        }
        TreeNode *node = root, *prev_node = nullptr;

        while (node != nullptr)
        {
            prev_node = node;
            if (val < node->val)
            {
                node = node->left;
            }
            else
            {
                node = node->right;
            }
        }
        if (val < prev_node->val)
        {
            prev_node->left = new TreeNode(val);
        }
        else
        {
            prev_node->right = new TreeNode(val);
        }
        return root;
    }
};
int main()
{
    Solution obj;
    return 0;
}