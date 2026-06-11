#include "../shared/tree-node.hpp"
#include <bits/stdc++.h>
#include <utility>
using namespace std;
class Solution {
private:
  TreeNode *first_violation;
  TreeNode *second_violation;
  TreeNode *last_violation;
  TreeNode *prev_node;

  void detect(TreeNode *curr) {
    if (this->prev_node != nullptr && (curr->val < this->prev_node->val)) {
      // If this is the first violation mark the nodes as first and second
      if (this->first_violation == nullptr) {
        this->first_violation = this->prev_node;
        this->second_violation = curr;
      }
      // if this the second violation mark this node as last
      else {
        this->last_violation = curr;
      }
    }
    // any way mark the current node as previous before moving on
    this->prev_node = curr;
  }

  // inorder morris traversal to visit nodes in ascending order
  void traverse_and_detect(TreeNode *root) {
    TreeNode *curr = root;
    while (curr != nullptr) {
      if (curr->left == nullptr) {
        detect(curr);
        curr = curr->right;
      } else {
        TreeNode *previous = curr->left;
        while (previous->right != nullptr && previous->right != curr) {
          previous = previous->right;
        }
        if (previous->right == nullptr) {
          previous->right = curr;
          curr = curr->left;
        }
        // previous-> right == curr
        else {
          previous->right = nullptr;
          detect(curr);
          curr = curr->right;
        }
      }
    }
  }

public:
  Solution() {
    first_violation = second_violation = last_violation = nullptr;
    prev_node = new TreeNode(INT_MIN);
  }
  void recoverTree(TreeNode *root) {
    traverse_and_detect(root);
    // non adjuscent BST violation
    if (this->first_violation != nullptr && this->last_violation != nullptr) {
      swap(this->first_violation->val, this->last_violation->val);
    }
    // adjuscent BST violation
    else if (this->first_violation != nullptr &&
             this->second_violation != nullptr) {
      swap(this->first_violation->val, this->second_violation->val);
    }
  }
};
int main() {
  Solution obj;
  return 0;
}
