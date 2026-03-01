#include <bits/stdc++.h>
#include "../shared/tree-node.hpp"
class Solution
{
public:
    std::pair<int, int> inOrderSuccessorAndPredecessor(TreeNode *root, int key)
    {
        if (root == nullptr)
            return {-1, -1};
        int succ = -1, pred = -1;
        TreeNode *currNode = root;
        while (currNode != nullptr)
        {
            if (currNode->val < key)
            {
                pred = currNode->val;
                currNode = currNode->right;
            }
            else if (currNode->val == key)
            {
                break;
            }
            else
            {
                succ = currNode->val;
                currNode = currNode->left;
            }
        }
        return {pred, succ};
    }
};
int main()
{
    int levels;
    std::cin >> levels;
    int n = pow(2, levels) - 1;
    std::vector<TreeNode *> bst(n);
    int x;
    for (int i = 0; i < n; i++)
    {
        std::cin >> x;
        // parsing the current node and back linking it to parent node in one go
        if (x != -1)
        {
            bst[i] = new TreeNode(x);
            if (i % 2 != 0)
            {
                // >> 1  = /2
                int j = (i - 1) >> 1;
                if (j >= 0)
                {
                    bst[j]->left = bst[i];
                }
            }
            else
            {
                int j = (i - 2) >> 1;
                if (j >= 0)
                {
                    bst[j]->right = bst[i];
                }
            }
        }
    }
    int key;
    std::cin >> key;
    TreeNode *root = bst[0];
    Solution obj;
    std::pair<int, int> predSucc = obj.inOrderSuccessorAndPredecessor(root, key);
    std::cout << "predecessor: " << predSucc.first << ", successor: " << predSucc.second << std::endl;
    return 0;
}