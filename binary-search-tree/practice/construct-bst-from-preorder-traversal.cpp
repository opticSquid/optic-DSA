#include <bits/stdc++.h>
#include "../shared/tree-node.hpp"
using namespace std;
class Solution
{
private:
    TreeNode *construct(vector<int> &preorder, int &pos, int upb)
    {
        if (pos == preorder.size() || preorder[pos] > upb)
            return nullptr;
        TreeNode *node = new TreeNode(preorder[pos++]);
        node->left = construct(preorder, pos, node->val);
        node->right = construct(preorder, pos, upb);
        return node;
    }

public:
    TreeNode *
    bstFromPreorder(vector<int> &preorder)
    {
        if (preorder.empty())
            return nullptr;
        int i = 0;
        return construct(preorder, i, INT_MAX);
    }
};
vector<int> levelOrderTraversal(TreeNode *root)
{
    if (root == nullptr)
    {
        return {};
    }
    queue<TreeNode *> q;
    vector<int> res;
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
        res.insert(res.end(), lvl.begin(), lvl.end());
    }
    return res;
}
int main()
{
    vector<int> vec = {8, 5, 1, 7, 10, 12};
    Solution obj;
    TreeNode *root = obj.bstFromPreorder(vec);
    vector<int> res = levelOrderTraversal(root);
    for (const int &i : res)
    {
        cout << i << "-> ";
    }
    cout << endl;
    return 0;
}