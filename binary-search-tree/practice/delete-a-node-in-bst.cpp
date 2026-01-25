#include <bits/stdc++.h>
#include "../shared/tree-node.hpp"
using namespace std;
class Solution
{
private:
    TreeNode *findLastRight(TreeNode *root)
    {
        while (root->right != nullptr)
        {
            root = root->right;
        }
        return root;
    }
    TreeNode *helper(TreeNode *root)
    {
        if (root->left == nullptr)
        {
            return root->right;
        }
        else if (root->right == nullptr)
        {
            return root->left;
        }
        TreeNode *rightChild = root->right;
        TreeNode *lastRight = findLastRight(root->left);
        lastRight->right = rightChild;
        return root->left;
    }

public:
    TreeNode *deleteNode(TreeNode *root, int key)
    {
        if (root == nullptr)
        {
            return nullptr;
        }
        TreeNode *dummy = root;
        if (dummy->val == key)
        {
            return helper(dummy);
        }
        while (dummy != nullptr)
        {
            if (dummy->val > key)
            {
                if (dummy->left != nullptr && dummy->left->val == key)
                {
                    TreeNode *node = dummy->left;
                    dummy->left = helper(dummy->left);
                    delete node;
                    break;
                }
                else
                {
                    dummy = dummy->left;
                }
            }
            else
            {
                if (dummy->right != nullptr && dummy->right->val == key)
                {
                    TreeNode *node = dummy->right;
                    dummy->right = helper(dummy->right);
                    delete node;
                    break;
                }
                else
                {
                    dummy = dummy->right;
                }
            }
        }
        return root;
    }
};
int main()
{
    Solution obj;
    return 0;
}