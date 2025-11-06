#include <bits/stdc++.h>
#include "../shared/tree-node.hpp"
using namespace std;
using Node = TreeNode;
class Solution
{
private:
    vector<int> boundaryNodes;
    bool isLeaf(Node *node)
    {
        return node != nullptr && node->left == nullptr && node->right == nullptr;
    }

    void addLeftBoundary(Node *node)
    {
        Node *curr = node->left;
        while (!isLeaf(curr))
        {
            boundaryNodes.push_back(curr->val);
            if (curr->left != nullptr)
            {
                curr = curr->left;
            }
            if (curr->left == nullptr && curr->right != nullptr)
            {
                curr = curr->right;
            }
        }
    }

    void addLeaves(Node *node)
    {
        if (isLeaf(node))
        {
            boundaryNodes.push_back(node->val);
        }
        if (node->left != nullptr)
        {
            addLeaves(node->left);
        }
        if (node->right != nullptr)
        {
            addLeaves(node->right);
        }
    }

    void addRightBoundary(Node *node)
    {
        vector<int>::iterator prevLast = boundaryNodes.end() - 1;
        Node *curr = node->right;
        while (!isLeaf(curr))
        {
            boundaryNodes.push_back(curr->val);
            if (curr->right != nullptr)
            {
                curr = curr->right;
            }
            if (curr->right == nullptr && curr->left != nullptr)
            {
                curr = curr->left;
            }
        }
        vector<int>::iterator currentLast = boundaryNodes.end() - 1;
        reverse(prevLast + 1, currentLast);
    }

public:
    vector<int> boundaryTraversal(Node *root)
    {
        if (root == nullptr)
        {
            return boundaryNodes;
        }
        if (!isLeaf(root))
        {
            boundaryNodes.push_back(root->val);
        }
        addLeftBoundary(root);
        addLeaves(root);
        addRightBoundary(root);
        return boundaryNodes;
    }
};
void deleteTree(Node *);
int main()
{
    Node *root = new Node(1);
    root->right = new Node(2);
    root->right->left = new Node(3);
    root->right->right = new Node(4);
    Solution obj;
    for (int i : obj.boundaryTraversal(root))
    {
        cout << i << ", ";
    }
    cout << endl;
    deleteTree(root);
    return 0;
}

void deleteTree(Node *node)
{
    if (node == nullptr)
    {
        return;
    }
    deleteTree(node->left);
    deleteTree(node->right);
    delete node;
}