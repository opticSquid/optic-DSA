#include <bits/stdc++.h>
#include "../shared/tree-node.hpp"
using namespace std;
class Solution
{
public:
    void flatten(TreeNode *root)
    {
        if (root == nullptr)
            return;
        TreeNode *dummyHead = new TreeNode(-1);
        TreeNode *iter = dummyHead;
        stack<TreeNode *> s;
        s.push(root);
        while (!s.empty())
        {
            TreeNode *front = s.top();
            s.pop();
            if (front->right != nullptr)
            {
                s.push(front->right);
                front->right = nullptr;
            }
            if (front->left != nullptr)
            {
                s.push(front->left);
                front->left = nullptr;
            }
            iter->right = front;
            iter = front;
        }
        root = dummyHead->right;
        delete dummyHead;
    }
};
int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->right->right = new TreeNode(5);
    root->right->right->left = new TreeNode(6);
    root->right->right->right = new TreeNode(7);
    root->right->right->left->left = new TreeNode(9);
    root->right->right->left->right = new TreeNode(10);
    root->right->right->right->right = new TreeNode(8);
    Solution obj;
    obj.flatten(root);
    TreeNode *prevNode;
    while (root != nullptr)
    {
        cout << root->val << "->";
        prevNode = root;
        root = root->right;
        delete prevNode;
    }
    cout << endl;
    return 0;
}