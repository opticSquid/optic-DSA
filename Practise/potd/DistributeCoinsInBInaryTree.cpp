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
    int distribute(TreeNode *node, TreeNode *parent)
    {
        if (node == nullptr)
        {
            return 0;
        }
        int moves = distribute(node->left, node) + distribute(node->right, node);
        int extra = node->val - 1;
        if (parent != nullptr)
        {
            parent->val += extra;
        }
        moves += abs(extra);
        return moves;
    }

public:
    int distributeCoins(TreeNode *root)
    {
        return distribute(root, nullptr);
    }
};
int main()
{

    Solution obj;
    return 0;
}