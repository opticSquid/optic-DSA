#include <bits/stdc++.h>
#include <../shared/tree-node.hpp>
using namespace std;
using Node = TreeNode;
class Solution
{
public:
    bool isSumProperty(Node *root)
    {
        if (root == nullptr || (root->left == nullptr && root->right == nullptr))
        {
            return true;
        }
        int child = 0;
        if (root->left != nullptr)
        {
            child += root->left->val;
        }
        if (root->right != nullptr)
        {
            child += root->right->val;
        }
        return (root->val == child) && isSumProperty(root->left) && isSumProperty(root->right);
    }

    void changeTree(Node *root)
    {
        if (root == nullptr)
        {
            return;
        }
        int child = 0;
        if (root->left != nullptr)
        {
            child += root->left->val;
        }
        if (root->right != nullptr)
        {
            child += root->right->val;
        }

        if (child >= root->val)
        {
            root->val = child;
        }
        else
        {
            if (root->left != nullptr)
            {
                root->left->val = root->val;
            }
            else if (root->right != nullptr)
            {
                root->right->val = root->val;
            }
        }
        changeTree(root->left);
        changeTree(root->right);

        int tot = 0;

        if (root->left != nullptr)
        {
            tot += root->left->val;
        }

        if (root->right != nullptr)
        {
            tot += root->right->val;
        }

        if (root->left != nullptr || root->right != nullptr)
        {
            root->val = tot;
        }
    }
};
int main()
{
    Solution obj;
    return 0;
}