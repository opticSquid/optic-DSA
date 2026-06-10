#include "../shared/tree-node.hpp"
#include <bits/stdc++.h>
using namespace std;
class Solution {
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

public:
  bool findTarget(TreeNode *root, int k) {
    vector<int> nodes;
    this->morrisInOrder(root, nodes);
    unordered_set<int> st;
    int diff;
    for (int i = 0; i < nodes.size(); i++) {
      diff = k - nodes[i];
      if(st.find(diff)!= st.end()) {
          return true;
      }
      st.insert(nodes[i]);
    }
    return false;
  }
};
int main() {
  Solution obj;
  return 0;
}
