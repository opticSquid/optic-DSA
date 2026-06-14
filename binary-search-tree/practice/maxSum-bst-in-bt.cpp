#include "../shared/tree-node.hpp"
#include <bits/stdc++.h>
using namespace std;
class NodeValue
{
public:
  int minNode, maxNode, currSum;
  NodeValue(int minNode, int maxNode, int curSum)
      : minNode(minNode), maxNode(maxNode), currSum(curSum) {}
};
class Solution
{
private:
  int maxSum;
  // doing post order traversal because we need to check children before we
  // check root
  NodeValue maxSumBstSubtreeHelper(TreeNode *root)
  {
    // An empty tree is a valid BST of size 0
    if (root == nullptr)
    {
      return NodeValue(INT_MAX, INT_MIN, 0);
    }
    auto left = maxSumBstSubtreeHelper(root->left);
    auto right = maxSumBstSubtreeHelper(root->right);
    // left->max < root->val < right-> min => Valid BST
    if (left.maxNode < root->val && root->val < right.minNode)
    {
      int currSum = left.currSum + right.currSum + root->val;
      this->maxSum = max(this->maxSum, currSum);
      return NodeValue(min(left.minNode, root->val), max(root->val, right.maxNode), currSum);
    }
    // The childrens are not valid BST so, root can not be a valid BST so,
    // returning a invalid BST
    return NodeValue(INT_MIN, INT_MAX, max(left.currSum, right.currSum));
  }

public:
  Solution() : maxSum(0) {}
  int maxSumBST(TreeNode *root)
  {
    maxSumBstSubtreeHelper(root);
    return this->maxSum;
  }
};
int main()
{
  TreeNode *root = new TreeNode(4);
  root->left = new TreeNode(8);
  root->left->left = new TreeNode(6);
  root->left->left->left = new TreeNode(9);
  root->left->right = new TreeNode(1);
  root->left->right->left = new TreeNode(-5);
  root->left->right->left->right = new TreeNode(-3);
  root->left->right->right = new TreeNode(4);
  root->left->right->right->right = new TreeNode(10);
  Solution obj;
  cout << "res: " << obj.maxSumBST(root) << endl;
  return 0;
}
