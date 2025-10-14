#include <bits/stdc++.h>
#include "./shared/tree-node.hpp"
using namespace std;
class Solution
{
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        if (root == nullptr)
        {
            return {};
        }
        queue<TreeNode *> q;
        vector<vector<int>> res;
        q.push(root);
        while (!q.empty())
        {
            int size = q.size();
            vector<int> lvl;
            for (int i = 0; i < size; i++)
            {
                TreeNode *node = q.front();
                q.pop();
                lvl.push_back(node->val);
                if (node->left != nullptr)
                {
                    q.push(node->left);
                }
                if (node->right != nullptr)
                {
                    q.push(node->right);
                }
            }
            res.push_back(lvl);
        }
        return res;
    }
};
int main()
{
    Solution obj;
    return 0;
}