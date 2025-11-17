#include <bits/stdc++.h>
#include "../shared/tree-node.hpp"
using namespace std;
class Solution
{
public:
    int widthOfBinaryTree(TreeNode *root)
    {
        if (root == nullptr)
        {
            return 0;
        }
        long maxWidth = 0l;
        queue<pair<TreeNode *, long>> q;
        q.push({root, 0l});
        while (!q.empty())
        {
            int size = q.size();
            long minIndex = q.front().second;
            long first = 0;
            long last = 0;
            for (int i = 0; i < size; i++)
            {
                long currIndex = q.front().second - minIndex;
                TreeNode *node = q.front().first;
                q.pop();

                if (i == 0)
                {
                    first = currIndex;
                }
                if (i == size - 1)
                {
                    last = currIndex;
                }
                if (node->left != nullptr)
                {
                    q.push({node->left, (long)2 * currIndex + 1});
                }
                if (node->right != nullptr)
                {
                    q.push({node->right, (long)2 * currIndex + 2});
                }
            }

            maxWidth = max(maxWidth, last - first + 1);
        }
        return (int)maxWidth;
    }
};
int main()
{
    Solution obj;
    return 0;
}