#include <bits/stdc++.h>
#include "../shared/tree-node.hpp"
using namespace std;
class Solution
{
public:
    pair<int, int> minMaxInBST(TreeNode *root)
    {
        if (!root)
            return {};

        TreeNode *mn = root, *mx = root;

        while (mn && mn->left)
            mn = mn->left; // Find Min
        while (mx && mx->right)
            mx = mx->right; // Find Max

        return {mn->val, mx->val};
    }
};
int main()
{
    Solution obj;
    return 0;
}