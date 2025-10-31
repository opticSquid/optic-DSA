#include <bits/stdc++.h>
#include "../shared/tree-node.hpp"
using namespace std;
class Solution
{
private:
    int calcSum(TreeNode *node, int &sum)
    {
        if (node == nullptr)
        {
            return 0;
        }
        int ls = max(0, calcSum(node->left, sum));
        int rs = max(0, calcSum(node->right, sum));
        sum = max(sum, ls + rs + node->val);
        return node->val + max(ls, rs);
    }

public:
    int maxPathSum(TreeNode *root)
    {
        int summ = INT_MIN;
        calcSum(root, summ);
        return summ;
    }
};
int main()
{
    Solution obj;
    return 0;
}