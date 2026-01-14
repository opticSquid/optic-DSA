#include <bits/stdc++.h>
#include "../shared/tree-node.hpp"
using namespace std;
class Solution
{
public:
    pair<int, int> minMaxInBST(TreeNode *root, int val)
    {
        if (root == nullptr)
        {
            return {};
        }
        TreeNode *node = root, *mn = root, *mx = root;
        while (mn->left != nullptr || mx->right != nullptr)
        {
            if (mn->left != nullptr)
            {
                mn = mn->left;
            }
            if (mx->right != nullptr)
            {
                mx = mx->right;
            }
        }
        return {mn->val, mx->val};
    }
};
int main()
{
    Solution obj;
    return 0;
}