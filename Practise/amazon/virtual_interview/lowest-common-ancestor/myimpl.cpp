#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
private:
    int findCommonAncestor(pair<TreeNode *, TreeNode *> locations, unordered_map<TreeNode *, pair<TreeNode *, int>> reverseTree)
    {
        stack<TreeNode *> st;
        st.push(locations.first);
        while (!st.empty())
        {
            TreeNode *node = st.top();
            st.pop();
            pair<TreeNode *, int> parent = reverseTree[node];
            parent.second = 1;
            st.push(parent.first);
            reverseTree[node] = parent;
        }
    }
    pair<TreeNode *, TreeNode *> bfsToReveseAndFindPQ(TreeNode *root, TreeNode *p, TreeNode *q, unordered_map<TreeNode *, pair<TreeNode *, int>> reverseTree)
    {
        queue<TreeNode *> queue;
        queue.push(root);
        pair<TreeNode *, TreeNode *> res;
        reverseTree[root] = {nullptr, 0};
        while (!queue.empty())
        {
            TreeNode *node = queue.front();
            queue.pop();
            if (node->val == p->val)
            {
                res.first = node;
            }
            else if (node->val == q->val)
            {
                res.second = node;
            }
            if (node->left)
            {
                reverseTree[node->left] = {node, 0};
                queue.push(node->left);
            }
            if (node->right)
            {
                reverseTree[node->right] = {node, 0};
                queue.push(node->right);
            }
        }
        return res;
    }

public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        unordered_map<TreeNode *, pair<TreeNode *, int>> reverseTree;
        pair<TreeNode *, TreeNode *> locations = bfsToReveseAndFindPQ(root, p, q, reverseTree);
    }
};
int main()
{
    Solution obj;
    return 0;
}