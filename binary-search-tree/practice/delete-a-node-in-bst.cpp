#include <bits/stdc++.h>
#include "../shared/tree-node.hpp"
using namespace std;
class Solution
{
public:
    TreeNode *deleteNode(TreeNode *root, int key)
    {
        TreeNode *curr = root, *parent = nullptr;
        while (curr != nullptr && curr->val != key)
        {
            parent = curr;
            if (key < curr->val)
            {
                curr = curr->left;
            }
            else
            {
                curr = curr->right;
            }
        }
        if (curr != nullptr)
        {
            // Node has 0 or 1 child
            if (curr->left == nullptr || curr->right == nullptr)
            {
                TreeNode *child = curr->left != nullptr ? curr->left : curr->right;
                if (parent == nullptr)
                {
                    return child; // key is in root only
                }
                if (parent->left == curr)
                {
                    parent->left = child;
                }
                else
                {
                    parent->right = child;
                }
                delete curr;
            }
            else
            {
                // Find the In-order Successor (leftmost in right subtree)
                TreeNode *successorParent = curr;
                TreeNode *successor = curr->right;
                while (successor->left != nullptr)
                {
                    successorParent = successor;
                    successor = successor->left;
                }
                // Replace current value with successor's value
                curr->val = successor->val;
                // Delete the successor node
                if (successorParent->left == successor)
                {
                    successorParent->left = successor->right;
                }
                else
                {
                    successorParent->right = successor->right;
                }
                delete successor;
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