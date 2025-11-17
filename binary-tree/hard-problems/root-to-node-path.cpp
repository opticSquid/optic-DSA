#include <bits/stdc++.h>
#include "../shared/tree-node.hpp"
using namespace std;
class Solution
{
private:
    bool traverse(TreeNode *node, const int *key, vector<int> &path)
    {
        if (node == nullptr)
        {
            return false;
        }
        path.push_back(node->val);
        if (node->val == *key)
        {
            return true;
        }
        // if found in any one of the sub trees
        if (traverse(node->left, key, path) || traverse(node->right, key, path))
        {
            return true;
        }
        // if not found in both subtree
        path.pop_back();
        return false;
    }

public:
    vector<int> rootToNodePath(TreeNode *root, int val)
    {
        if (root == nullptr)
        {
            return {};
        }
        vector<int> path;
        traverse(root, &val, path);
        return path;
    }
};
int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    root->right->right->left = new TreeNode(8);
    root->right->right->right = new TreeNode(9);
    root->right->right->right->left = new TreeNode(10);
    root->right->right->right->right = new TreeNode(11);
    Solution obj;
    for (const int &i : obj.rootToNodePath(root, 8))
    {
        cout << i << "-> ";
    }
    cout << endl;
    return 0;
}