#include <bits/stdc++.h>
#include "../shared/tree-node.hpp"
using namespace std;
class Solution
{
private:
    TreeNode *build(vector<int> &preorder, int prestart, int preend, vector<int> &inorder, int instart, int inend, unordered_map<int, int> &inmap)
    {
        if (prestart > preend || instart > inend)
        {
            return nullptr;
        }
        TreeNode *root = new TreeNode(preorder[prestart]);
        int inroot = inmap[root->val];
        int numsleft = inroot - instart;
        root->left = build(preorder, prestart + 1, prestart + numsleft, inorder, instart, inroot - 1, inmap);
        root->right = build(preorder, prestart + numsleft + 1, preend, inorder, inroot + 1, inend, inmap);
        return root;
    }

public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        unordered_map<int, int> inmap;
        for (int i = 0; i < inorder.size(); i++)
        {
            inmap[inorder[i]] = i;
        }
        return build(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, inmap);
    }
};
void printPreOrder(TreeNode *node)
{
    if (node == nullptr)
    {
        cout << "null" << " ";
        return;
    }
    cout << node->val << " ";
    printPreOrder(node->left);
    printPreOrder(node->right);
}
void deleteTree(TreeNode *node)
{
    if (node == nullptr)
    {
        return;
    }
    deleteTree(node->left);
    deleteTree(node->right);
    delete node;
}
int main()
{
    int size;
    cin >> size;
    vector<int> preorder, inorder;
    preorder.reserve(size);
    inorder.reserve(size);
    int x;
    for (int i = 0; i < size; i++)
    {
        cin >> x;
        preorder.push_back(x);
    }
    for (int i = 0; i < size; i++)
    {
        cin >> x;
        inorder.push_back(x);
    }
    Solution obj;
    TreeNode *root = obj.buildTree(preorder, inorder);
    printPreOrder(root);
    cout << endl;
    deleteTree(root);
    return 0;
}