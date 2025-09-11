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
    int findMax(TreeNode *node, int *maxD)
    {
        if (node == nullptr)
        {
            return 0;
        }
        int lh = findMax(node->left, maxD);
        int rh = findMax(node->right, maxD);
        *maxD = max(*maxD, lh + rh);
        return 1 + max(lh, rh);
    }

public:
    int diameterOfBinaryTree(TreeNode *root)
    {
        int maxD = 0;
        findMax(root, &maxD);
        return maxD;
    }
};
int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    Solution obj;
    cout << obj.diameterOfBinaryTree(root) << endl;
    return 0;
}