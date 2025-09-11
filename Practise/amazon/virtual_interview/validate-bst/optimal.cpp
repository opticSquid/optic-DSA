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
private:
    bool check(TreeNode *node, long minVal, long maxVal)
    {
        if (node == NULL)
        {
            return true;
        }
        if ((node->val >= maxVal) || (node->val <= minVal))
        {
            return false;
        }
        bool l = check(node->left, minVal, node->val);
        bool r = check(node->right, node->val, maxVal);
        return l && r;
    }

public:
    bool isValidBST(TreeNode *root)
    {
        return check(root, LONG_MIN, LONG_MAX);
    }
};
int main()
{
    Solution obj;
    return 0;
}