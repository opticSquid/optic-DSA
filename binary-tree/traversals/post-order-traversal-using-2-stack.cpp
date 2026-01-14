#include <bits/stdc++.h>
#include "../shared/tree-node.hpp"
using namespace std;
class Solution
{
public:
    vector<int> postorderTraversal(TreeNode *root)
    {
        if (root == nullptr)
        {
            return {};
        }
        stack<TreeNode *> st1, st2;
        st1.push(root);
        while (!st1.empty())
        {
            TreeNode *node = st1.top();
            st1.pop();
            st2.push(node);
            if (node->left != nullptr)
            {
                st1.push(node->left);
            }
            if (node->right != nullptr)
            {
                st1.push(node->right);
            }
        }
        vector<int> res;
        while (!st2.empty())
        {
            res.push_back(st2.top()->val);
            st2.pop();
        }
        return res;
    }
};
int main()
{
    Solution obj;
    return 0;
}