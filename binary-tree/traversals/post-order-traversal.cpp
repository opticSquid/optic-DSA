#include <bits/stdc++.h>
#include "../shared/tree-node.hpp"
using namespace std;
class Solution
{
private:
    void traverse(TreeNode *node, vector<int> &res)
    {
        if (node->left != nullptr)
            traverse(node->left, res);
        if (node->right != nullptr)
            traverse(node->right, res);
        res.push_back(node->val);
    }

public:
    vector<int> postorderTraversal(TreeNode *root)
    {
        if (root == nullptr)
        {
            return {};
        }
        vector<int> res;
        traverse(root, res);
        return res;
    }
};
int main()
{
    Solution obj;
    return 0;
}