#include <bits/stdc++.h>
#include "./shared/tree-node.hpp"
using namespace std;
class Solution
{
public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        if (root == nullptr)
        {
            return {};
        }
        stack<TreeNode *> st;
        vector<int> res;
        TreeNode *currNode = root;
        while (currNode != nullptr || !st.empty())
        {
            while (currNode != nullptr)
            {
                st.push(currNode);
                currNode = currNode->left;
            }
            currNode = st.top();
            st.pop();
            res.push_back(currNode->val);
            currNode = currNode->right;
        }
        return res;
    }
};
int main()
{
    Solution obj;
    return 0;
}