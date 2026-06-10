#include "../shared/tree-node.hpp"
#include <bits/stdc++.h>
using namespace std;
class BruteForceSolution {
private:
  vector<int> nodes;
  void morrisPreOrder(TreeNode *root) {
    TreeNode *curr = root;
    while (curr != nullptr) {
      if (curr->left == nullptr) {
        this->nodes.push_back(curr->val);
        curr = curr->right;
      } else {
        TreeNode *prev = curr->left;
        while (prev->right != nullptr && prev->right != curr) {
          prev = prev->right;
        }
        if (prev->right == nullptr) {
          prev->right = curr;
          this->nodes.push_back(curr->val);
          curr = curr->left;
        } else {
          prev->right = nullptr;
          curr = curr->right;
        }
      }
    }
  }
};

class OptimalSolution {
private:
  void morrisInOrder(TreeNode *root, vector<int> &res) {
    TreeNode *curr = root;
    while (curr != nullptr) {
      if (curr->left == nullptr) {
        res.push_back(curr->val);
        curr = curr->right;
      } else {
        TreeNode *prev = curr->left;
        while (prev->right != nullptr && prev->right != curr) {
          prev = prev->right;
        }
        if (prev->right == nullptr) {
          prev->right = curr;
          curr = curr->left;
        } else {
          prev->right = nullptr;
          res.push_back(curr->val);
          curr = curr->right;
        }
      }
    }
  }
  // builds height balanced BST
  TreeNode *buildTree(vector<int> &nodes, int start, int end) {
    if (start > end)
      return nullptr;
    int mid = (start + end) / 2;
    TreeNode *root = new TreeNode(nodes[mid]);
    root->left = this->buildTree(nodes, start, mid - 1);
    root->right = this->buildTree(nodes, mid + 1, end);
    return root;
  }

public:
  TreeNode *merge(TreeNode *root1, TreeNode *root2) {
    vector<int> nodes1;
    vector<int> nodes2;
    vector<int> nodes3;
    // inorder traversal gives nodes in sorted order
    this->morrisInOrder(root1, nodes1);
    this->morrisInOrder(root2, nodes2);
    int p1 = 0, p2 = 0;
    // merge 2 sorted lists
    while (p1 < nodes1.size() && p2 < nodes2.size()) {
      if (nodes1[p1] < nodes2[p2]) {
        nodes3.push_back(nodes1[p1++]);
      } else {
        nodes3.push_back(nodes2[p2++]);
      }
    }
    while (p1 < nodes1.size()) {
      nodes3.push_back(nodes1[p1++]);
    }
    while (p2 < nodes2.size()) {
      nodes3.push_back(nodes2[p2++]);
    }
    // build balanced BST from merged sorted list
    return this->buildTree(nodes3, 0, nodes3.size() - 1);
  }
};
int main() {
  BruteForceSolution obj;
  return 0;
}
