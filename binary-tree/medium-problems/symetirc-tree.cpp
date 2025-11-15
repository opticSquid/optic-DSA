#include <bits/stdc++.h>
#include "./shared/tree-node.hpp";
using namespace std;
class Solution
{
private:
    bool isSymetricUtil(TreeNode *root_left, TreeNode *root_right)
    {
        if (root_left == nullptr || root_right == nullptr)
        {
            return root_left == root_right;
        }

        return (root_left->val == root_right->val) &&
               isSymetricUtil(root_left->left, root_right->right) &&
               isSymetricUtil(root_left->right, root_right->left);
    }

public:
    bool isSymmetric(TreeNode *root)
    {
        if (root == nullptr)
        {
            return true;
        }
        return isSymetricUtil(root->left, root->right);
    }
};
int main()
{
    Solution obj;
    return 0;
}