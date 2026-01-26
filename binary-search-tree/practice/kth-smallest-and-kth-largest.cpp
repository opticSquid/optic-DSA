#include <bits/stdc++.h>
#include "../shared/tree-node.hpp"
using namespace std;
class Solution
{
private:
    int inOrderTraversal(TreeNode *root, const int k)
    {
        int ctr = 0;
        TreeNode *currNode = root;
        stack<TreeNode *> st;
        int kSmall = INT_MAX;
        while (currNode != nullptr || !st.empty())
        {
            while (currNode != nullptr)
            {
                st.push(currNode);
                currNode = currNode->left;
            }
            currNode = st.top();
            st.pop();
            ctr++;
            if (ctr == k)
            {
                kSmall = currNode->val;
                break;
            }
            currNode = currNode->right;
        }
        return kSmall;
    }

    int reverseInOrderTraversal(TreeNode *root, const int k)
    {
        int ctr = 0;
        TreeNode *currNode = root;
        stack<TreeNode *> st;
        int kLarge = INT_MIN;
        while (currNode != nullptr || !st.empty())
        {
            while (currNode != nullptr)
            {
                st.push(currNode);
                currNode = currNode->right;
            }
            currNode = st.top();
            st.pop();
            ctr++;
            if (ctr == k)
            {
                kLarge = currNode->val;
                break;
            }
            currNode = currNode->left;
        }
        return kLarge;
    }

public:
    int kthSmallest(TreeNode *root, int k)
    {
        if (root == nullptr)
            return -1;
        return inOrderTraversal(root, k);
    }
};
int main()
{
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->left->right = new TreeNode(2);
    root->right = new TreeNode(4);
    Solution obj;
    cout << "K Small: " << obj.kthSmallest(root, 1) << endl;
    return 0;
}