#include <bits/stdc++.h>
#include "../shared/tree-node.hpp"
using namespace std;
class Solution
{
private:
    int calcHeight(TreeNode *node, int &diam)
    {
        if (node == nullptr)
        {
            return 0;
        }
        int lh = calcHeight(node->left, diam);
        int rh = calcHeight(node->right, diam);
        diam = max(diam, lh + rh);
        return 1 + max(lh, rh);
    }

public:
    int diameterOfBinaryTree(TreeNode *root)
    {
        int diameter = 0;
        calcHeight(root, diameter);
        return diameter;
    }
};
int main()
{
    Solution obj;
    return 0;
}