#include <bits/stdc++.h>
#include "../shared/tree-node.hpp"
using namespace std;
class Solution
{
private:
    void inOrderTraversal(TreeNode *node, int &k, int &res)
    {
        if (node != nullptr)
        {
            inOrderTraversal(node->left, k, res);
            if (--k == 0)
            {
                res = node->val;
                return;
            }
            inOrderTraversal(node->right, k, res);
        }
    }

    void reverseInOrderTraversal(TreeNode *node, int &k, int &res)
    {
        if (node != nullptr)
        {
            reverseInOrderTraversal(node->right, k, res);
            if (--k == 0)
            {
                res = node->val;
                return;
            }
            reverseInOrderTraversal(node->left, k, res);
        }
    }

public:
    vector<int> kLargeSmallest(TreeNode *root, int k)
    {
        if (root == nullptr)
            return {-1, -1};
        int k1 = k, k2 = k;
        int res1 = -1, res2 = -1;
        inOrderTraversal(root, k1, res1);
        reverseInOrderTraversal(root, k2, res2);
        return {res1, res2};
    }
};
int main()
{
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->left->right = new TreeNode(2);
    root->right = new TreeNode(4);
    Solution obj;
    vector<int> res = obj.kLargeSmallest(root, 1);
    cout << "K Small: " << res[0] << ", K Large: " << res[1] << endl;
    return 0;
}