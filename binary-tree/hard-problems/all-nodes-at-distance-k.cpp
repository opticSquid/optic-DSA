#include <bits/stdc++.h>
#include "../shared/tree-node.hpp"
using namespace std;
class Solution
{
private:
    void mapParents(TreeNode *root, unordered_map<TreeNode *, TreeNode *> &p_mp)
    {
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            TreeNode *node = q.front();
            q.pop();

            if (node->left != nullptr)
            {
                q.push(node->left);
                p_mp[node->left] = node;
            }
            if (node->right != nullptr)
            {
                q.push(node->right);
                p_mp[node->right] = node;
            }
        }
    }

public:
    vector<int> distanceK(TreeNode *root, TreeNode *target, int k)
    {
        if (root == nullptr || target == nullptr)
        {
            return {};
        }
        if (k == 0)
        {
            return {target->val};
        }
        unordered_map<TreeNode *, TreeNode *> p_mp;
        mapParents(root, p_mp);

        queue<TreeNode *> q;
        unordered_set<TreeNode *> vis;

        int curLvl = 0;
        q.push(target);
        vis.insert(target);

        while (!q.empty())
        {
            int size = q.size();
            if (curLvl++ == k)
            {
                break;
            }
            for (int i = 0; i < size; i++)
            {
                TreeNode *node = q.front();
                q.pop();

                // travel upward
                // only if a parent exists of the node (for root node there would be no parent) and parent is not visited
                if (p_mp.find(node) != p_mp.end() && vis.find(p_mp[node]) == vis.end())
                {
                    vis.insert(p_mp[node]);
                    q.push(p_mp[node]);
                }

                // travel downward left
                // Only if node's left exist and is not visited
                if (node->left != nullptr && vis.find(node->left) == vis.end())
                {
                    vis.insert(node->left);
                    q.push(node->left);
                }

                // travel downward right
                // Only if node's left exist and is not visited
                if (node->right != nullptr && vis.find(node->right) == vis.end())
                {
                    vis.insert(node->right);
                    q.push(node->right);
                }
            }
        }

        vector<int> res;
        while (!q.empty())
        {
            res.push_back(q.front()->val);
            q.pop();
        }
        return res;
    }
};
int main()
{
    Solution obj;
    return 0;
}