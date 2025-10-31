#include <bits/stdc++.h>
#include "../shared/tree-node.hpp"
using namespace std;
class Solution
{
public:
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        if (p == nullptr || q == nullptr)
        {
            return p == q;
        }
        return (p->val == q->val) && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};
int main()
{
    Solution obj;
    return 0;
}