#include <bits/stdc++.h>
#include "./shared/tree-node.hpp"
using namespace std;
class Solution
{
public:
    vector<vector<int>> allInOneTraversal(TreeNode *root)
    {
        if (root == nullptr)
        {
            return {};
        }
        stack<pair<TreeNode *, int>> st;
        vector<vector<int>> mpp(3);
        st.push({root, 0});
        while (!st.empty())
        {
            const auto it = st.top();
            TreeNode *node = it.first;
            int state = it.second;
            st.pop();
            switch (state)
            {
            case 0:
                mpp[state].push_back(node->val);
                st.push({node, state + 1});
                if (node->left != nullptr)
                {
                    st.push({node->left, 0});
                }
                break;

            case 1:
                mpp[state].push_back(node->val);
                st.push({node, state + 1});
                if (node->right != nullptr)
                {
                    st.push({node->right, 0});
                }
                break;

            case 2:
                mpp[state].push_back(node->val);
                break;

            default:
                break;
            }
        }
        return mpp;
    }
};
int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    Solution obj;
    for (const auto &it : obj.allInOneTraversal(root))
    {
        for (const auto &i : it)
        {
            cout << i << ", ";
        }
        cout << "\n";
    }
    cout << endl;
    delete root->right->right;
    delete root->right->left;
    delete root->right;
    delete root->left->right;
    delete root->left->left;
    delete root->left;
    delete root;
    return 0;
}