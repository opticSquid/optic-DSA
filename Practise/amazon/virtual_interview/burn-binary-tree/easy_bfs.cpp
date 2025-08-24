#include <bits/stdc++.h>
using namespace std;
//  Definition for a binary tree node.
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
private:
    int findMaxDistance(map<TreeNode *, TreeNode *> &mpp, TreeNode *target)
    {
        queue<TreeNode *> q;
        q.push(target);
        map<TreeNode *, bool> vis;
        vis[target] = true;
        int maxi = 0;
        while (!q.empty())
        {
            int sz = q.size();
            bool fl = false;
            for (int i = 0; i < sz; i++)
            {
                TreeNode *node = q.front();
                q.pop();
                if (node->left && !vis[node->left])
                {
                    fl = true;
                    vis[node->left] = true;
                    q.push(node->left);
                }
                if (node->right && !vis[node->right])
                {
                    fl = true;
                    vis[node->right] = true;
                    q.push(node->right);
                }
                if (mpp[node] && !vis[mpp[node]])
                {
                    fl = true;
                    vis[mpp[node]] = true;
                    q.push(mpp[node]);
                }
            }
            if (fl)
                maxi++;
        }
        return maxi;
    }
    TreeNode *bfsToMapParents(TreeNode *root, map<TreeNode *, TreeNode *> &mpp, int start)
    {
        queue<TreeNode *> q;
        q.push(root);
        TreeNode *res;
        while (!q.empty())
        {
            TreeNode *node = q.front();
            if (node->val == start)
            {
                res = node;
            }
            q.pop();
            if (node->left)
            {
                mpp[node->left] = node;
                q.push(node->left);
            }
            if (node->right)
            {
                mpp[node->right] = node;
                q.push(node->right);
            }
        }
        return res;
    }

public:
    int amountOfTime(TreeNode *root, int start)
    {
        map<TreeNode *, TreeNode *> mpp;
        TreeNode *target = bfsToMapParents(root, mpp, start);
        int maxi = findMaxDistance(mpp, target);
        return maxi;
    }
};
int main()
{
    Solution obj;
    return 0;
}