#include <bits/stdc++.h>
#include "../shared/tree-node.hpp"
using namespace std;
class Solution
{
private:
    TreeNode *build(const int pst_start, const int pst_end, const int in_start, const int in_end, vector<int> &pstordr, vector<int> &inordr, unordered_map<int, int> &inmap)
    {
        if (pst_start > pst_end || in_start > in_end)
        {
            return nullptr;
        }
        TreeNode *root = new TreeNode(pstordr[pst_end]);
        int in_root_idx = inmap[root->val];
        int lft_sub_tree = in_root_idx - in_start;
        root->left = build(pst_start, pst_start + lft_sub_tree - 1, in_start, in_root_idx - 1, pstordr, inordr, inmap);
        root->right = build(pst_start + lft_sub_tree, pst_end - 1, in_root_idx + 1, in_end, pstordr, inordr, inmap);
        return root;
    }

public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        unordered_map<int, int> inmap;
        for (int i = 0; i < inorder.size(); i++)
        {
            inmap[inorder[i]] = i;
        }
        return build(0, postorder.size() - 1, 0, inorder.size() - 1, postorder, inorder, inmap);
    }
};
void print_and_delete_preorder(TreeNode *node)
{
    if (node != nullptr)
    {
        cout << node->val << ", ";
        print_and_delete_preorder(node->left);
        print_and_delete_preorder(node->right);
        delete node;
    }
    else
    {
        cout << "null" << ", ";
    }
}
int main()
{
    vector<int> inordr = {9, 3, 15, 20, 7};
    vector<int> pstordr = {9, 15, 7, 20, 3};
    Solution obj;
    TreeNode *root = obj.buildTree(inordr, pstordr);
    print_and_delete_preorder(root);
    cout << endl;
    return 0;
}