#include <bits/stdc++.h>
#include "../shared/tree-node.hpp"
using namespace std;
class Solution
{
public:
    vector<int> findFloorAndCeil(TreeNode *root, int num)
    {
        if (root == nullptr)
        {
            return {-1, -1};
        }
        TreeNode *currNode = root;
        int currCeil = -1, currFloor = -1;
        while (currNode != nullptr)
        {
            if (currNode->val == num)
            {
                return {num, num};
            }
            else if (currNode->val > num)
            {
                currCeil = currNode->val; // potential ceiling
                currNode = currNode->left;
            }
            else
            {

                currFloor = currNode->val; // potential floor
                currNode = currNode->right;
            }
        }
        return {currFloor, currCeil};
    }
};
int main()
{
    TreeNode *root = new TreeNode(10);
    root->left = new TreeNode(8);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(9);
    root->left->left->left = new TreeNode(4);
    root->left->left->right = new TreeNode(7);
    root->left->left->left->left = new TreeNode(2);
    root->left->left->left->right = new TreeNode(5);
    root->right = new TreeNode(12);
    root->right->left = new TreeNode(11);
    root->right->right = new TreeNode(14);
    root->right->right->left = new TreeNode(13);
    root->right->right->right = new TreeNode(16);
    root->right->right->right->left = new TreeNode(15);
    root->right->right->right->right = new TreeNode(18);
    root->right->right->right->right->left = new TreeNode(17);
    root->right->right->right->right->right = new TreeNode(20);
    Solution obj;
    vector<int> res = obj.findFloorAndCeil(root, 3);
    cout << "floor of 3 = " << res[0] << ", ceiling of 3 = " << res[1] << "\n";
    res = obj.findFloorAndCeil(root, 19);
    cout << "floor of 19 = " << res[0] << ", ceiling of 19 = " << res[1] << "\n";
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        TreeNode *node = q.front();
        q.pop();
        if (node->left != nullptr)
        {
            q.push(node->left);
        }
        if (node->right != nullptr)
        {
            q.push(node->right);
        }
        delete node;
    }
    return 0;
}