#include <bits/stdc++.h>
#include <climits>
#include "../shared/tree-node.hpp"
using namespace std;
class NodeValue {
public:
  int minNode, maxNode, maxSize;
  NodeValue(int minNode, int maxNode, int maxSize)
      : minNode(minNode), maxNode(maxNode), maxSize(maxSize) {}
};
class Solution {
    private:
        // doing post order traversal because we need to check children before we check root
        NodeValue largestBstSubtreeHelper(TreeNode *root) {
            // An empty tree is a valid BST of size 0
            if (root==nullptr) {
                return NodeValue(INT_MAX, INT_MIN, 0);
            }
            auto left = largestBstSubtreeHelper(root->left);
            auto right = largestBstSubtreeHelper(root->right);
            // left->max < root->val < right-> min => Valid BST
            if(left.maxNode < root->val && root->val < right.minNode) {
                return  NodeValue(min(left.minNode, root->val),max(root->val, right.maxNode),left.maxSize+right.maxSize+1);
            }
            // The childrens are not valid BST so, root can not be a valid BST so, returning a invalid BST
            return NodeValue(INT_MIN, INT_MAX,left.maxSize+right.maxSize+1);
        }
    public:
        int largestBST(TreeNode *root) {
            return largestBstSubtreeHelper(root).maxSize;
        }
};
int main() {
  Solution obj;
  return 0;
}
