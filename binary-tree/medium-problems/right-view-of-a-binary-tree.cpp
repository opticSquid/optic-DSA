#include <bits/stdc++.h>
#include "./shared/tree-node.hpp";
using namespace std;
class Solution
{
private:
    vector<int> ans;
    void traverse(TreeNode *node, int level)
    {
        if (node == nullptr)
        {
            return;
        }
        if (level == ans.size())
        {
            ans.push_back(node->val);
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
        return ans;
    }
};
int main()
{
    Solution obj;
    return 0;
}