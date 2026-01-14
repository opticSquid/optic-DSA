#include <bits/stdc++.h>
#include "../shared/tree-node.hpp"
using namespace std;

class Solution
{
public:
    vector<int> preorderTraversal(TreeNode *root)
    {
        if (root == nullptr)
        {
            return {};
        }
        stack<TreeNode *> st;
        st.push(root);
        vector<int> res;
        while (!st.empty())
        {
            TreeNode *node = st.top();
            st.pop();
            res.push_back(node->val);
            if (node->right != nullptr)
                st.push(node->right);
            if (node->left != nullptr)
                st.push(node->left);
        }
        return res;
    }
};
int main()
{
    Solution obj;
    return 0;
}