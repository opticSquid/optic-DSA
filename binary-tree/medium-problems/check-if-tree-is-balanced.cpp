#include <bits/stdc++.h>
#include "../shared/tree-node.hpp"
using namespace std;
class Solution
{
public:
    virtual bool isBalanced(TreeNode *root) = 0;
};
class MySolution : public Solution
{
private:
    pair<bool, int> checkBalanced(TreeNode *node)
    {
        if (node == nullptr)
        {
            return {true, 0};
        }
        if (node->left == nullptr && node->right == nullptr)
        {
            return {true, 1};
        }
        const auto [isBlncdLft, lftD] = checkBalanced(node->left);
        const auto [isBlncdR8, r8D] = checkBalanced(node->right);
        if (!isBlncdLft || !isBlncdR8)
        {
            return {false, 0};
        }
        else if (abs(lftD - r8D) > 1)
        {
            return {false, 0};
        }
        else
        {
            return {true, 1 + max(lftD, r8D)};
        }
    }

public:
    bool isBalanced(TreeNode *root)
    {
        if (root == nullptr)
        {
            return true;
        }
        else
        {
            return checkBalanced(root).first;
        }
    }
};
class OptimizedSolution : public Solution
{
private:
    int checkHeight(TreeNode *node)
    {
        if (!node)
            return 0;

        int left = checkHeight(node->left);
        if (left == -1)
            return -1; // left subtree not balanced

        int right = checkHeight(node->right);
        if (right == -1)
            return -1; // right subtree not balanced

        if (abs(left - right) > 1)
            return -1; // current node not balanced

        return 1 + max(left, right);
    }

public:
    bool isBalanced(TreeNode *root)
    {
        return checkHeight(root) != -1;
    }
};
int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->left->left = new TreeNode(4);
    root->left->left->right = new TreeNode(4);
    root->left->right = new TreeNode(3);
    root->right = new TreeNode(2);
    MySolution obj1;
    cout << obj1.isBalanced(root) << endl;
    return 0;
}