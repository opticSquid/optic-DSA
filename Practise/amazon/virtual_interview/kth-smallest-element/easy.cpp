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
    int inOrder(TreeNode *node, int *k, int *cnt)
    {
        if (node == NULL)
        {
            return -1;
        }
        int l = inOrder(node->left, k, cnt);
        if (l != -1)
        {
            return l;
        }
        (*cnt)++;
        if (*cnt == *k)
        {
            return node->val;
        }
        int r = inOrder(node->right, k, cnt);
        if (r != -1)
        {
            return r;
        }
        return -1;
    }

public:
    int kthSmallest(TreeNode *root, int k)
    {
        int cnt = 0;
        return inOrder(root, &k, &cnt);
    }
};
int main()
{
    Solution obj;
    return 0;
}