#include <bits/stdc++.h>
#include "../shared/tree-node.hpp"
using namespace std;
class Solution
{
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        if (root == nullptr)
        {
            return {};
        }
        else
        {
            queue<TreeNode *> q;
            vector<vector<int>> res;
            q.push(root);
            bool ltr = true;
            while (!q.empty())
            {
                int lvl_size = q.size();
                vector<int> curr_lvl(lvl_size);
                for (int i = 0; i < lvl_size; i++)
                {
                    TreeNode *n = q.front();
                    q.pop();
                    int idx = ltr ? i : lvl_size - i - 1;
                    curr_lvl[idx] = n->val;
                    if (n->left != nullptr)
                        q.push(n->left);
                    if (n->right != nullptr)
                        q.push(n->right);
                }
                res.push_back(curr_lvl);
                ltr = !ltr;
            }
            return res;
        }
    }
};
int main()
{
    Solution obj;
    return 0;
}