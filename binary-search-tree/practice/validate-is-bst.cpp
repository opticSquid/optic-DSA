#include <bits/stdc++.h>
#include "../shared/tree-node.hpp"
using namespace std;
class Solution
{
private:
    bool validate(TreeNode *node, long long minVal, long long maxVal)
    {
        if (node == nullptr)
        {
            return true;
        }
        if (node->val <= minVal || node->val >= maxVal)
        {
            return false;
        }
        return validate(node->left, minVal, node->val) && validate(node->right, node->val, maxVal);
    }

public:
    bool isValidBST_Morris(TreeNode *root)
    {
        TreeNode *currNode = root;
        TreeNode *prevNode = nullptr;
        bool isValid = true;
        while (currNode != nullptr)
        {
            if (currNode->left == nullptr)
            {
                if (prevNode != nullptr && currNode->val <= prevNode->val)
                {
                    isValid = false;
                }
                prevNode = currNode;
                currNode = currNode->right;
            }
            else
            {
                TreeNode *pre = currNode->left;
                while (pre->right != nullptr && pre->right != currNode)
                {
                    pre = pre->right;
                }
                if (pre->right == nullptr)
                {
                    pre->right = currNode;
                    currNode = currNode->left;
                }
                else
                {
                    pre->right = nullptr;
                    if (prevNode != nullptr && currNode->val <= prevNode->val)
                    {
                        isValid = false;
                    }
                    prevNode = currNode;
                    currNode = currNode->right;
                }
            }
        }
        return isValid;
    }
    bool isValidBST(TreeNode *root)
    {
        return validate(root, LONG_LONG_MIN, LONG_LONG_MAX);
    }
};
void deleteTree(TreeNode *node)
{
    if (node == nullptr)
    {
        return;
    }
    deleteTree(node->left);
    deleteTree(node->right);
    delete node;
}
int main()
{
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(6);
    root->right->left = new TreeNode(3);
    root->right->right = new TreeNode(7);
    Solution obj;
    string res = obj.isValidBST(root) ? "true" : "false";
    cout << res << endl;
    deleteTree(root);
    return 0;
}
