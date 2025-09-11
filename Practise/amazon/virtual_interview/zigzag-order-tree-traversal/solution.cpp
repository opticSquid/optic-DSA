#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution
{
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        if (root == nullptr)
        {
            return {};
        }
        queue<TreeNode *> q;
        vector<vector<int>> res;
        q.push(root);
        bool ltr = true;
        while (!q.empty())
        {
            int lvl_size = q.size();
            vector<int> cur_lvl(lvl_size);
            for (int i = 0; i < lvl_size; i++)
            {
                TreeNode *node = q.front();
                q.pop();
                int idx = ltr ? i : lvl_size - 1 - i;
                cur_lvl[idx] = node->val;
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
            res.push_back(cur_lvl);
            ltr = !ltr;
        }
        return res;
    }
};
int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->right->right = new TreeNode(5);
    Solution obj;
    for (vector<int> level : obj.zigzagLevelOrder(root))
    {
        cout << "[";
        for (int i : level)
        {
            cout << i << ", ";
        }
        cout << "], ";
    }
    cout << endl;
    return 0;
}