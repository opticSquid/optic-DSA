#include <bits/stdc++.h>
#include "./shared/tree-node.hpp";
using namespace std;
class Solution
{
private:
    queue<int> q;
    void traverse(TreeNode *node, int level)
    {
        if (node == nullptr)
        {
            return;
        }
        if (level == q.size())
        {
            q.push(node->val);
        }
        traverse(node->right, level + 1);
        traverse(node->left, level + 1);
    }

public:
    vector<int> rightSideView(TreeNode *root)
    {
        if (root == nullptr)
        {
            return {};
        }
        traverse(root, 0);
        vector<int> ans;
        while (!q.empty())
        {
            ans.push_back(q.front());
            q.pop();
        }
        return ans;
    }
};
int main()
{
    Solution obj;
    return 0;
}