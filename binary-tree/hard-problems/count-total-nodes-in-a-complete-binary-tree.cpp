#include <stack>
#include <../shared/tree-node.hpp>
using namespace std;
class Solution
{
private:
    int findHeight(TreeNode *node, bool shouldGoLeft)
    {
        int height = 0;
        while (node)
        {
            height++;
            node = shouldGoLeft ? node->left : node->right;
        }
        return height;
    }

public:
    int countNodesRecursive(TreeNode *root)
    {
        if (root == nullptr)
        {
            return 0;
        }

        int lh = findHeight(root, true);
        int rh = findHeight(root, false);
        if (lh == rh)
        {
            // basically 2^h -1
            return (1 << lh) - 1;
        }
        return 1 + countNodesRecursive(root->left) + countNodesRecursive(root->right);
    }
    int countNodesIterative(TreeNode *root)
    {
        if (root == nullptr)
        {
            return 0;
        }
        int totalCount = 0;
        stack<TreeNode *> st;
        st.push(root);
        while (!st.empty())
        {
            TreeNode *node = st.top();
            st.pop();
            int lh = findHeight(node, true);
            int rh = findHeight(node, false);
            if (lh == rh)
            {
                // basically 2^h -1
                totalCount += (1 << lh) - 1;
            }
            else
            {
                totalCount += 1;
                if (node->left != nullptr)
                {
                    st.push(node->left);
                }
                if (node->right != nullptr)
                {
                    st.push(node->right);
                }
            }
        }
        return totalCount;
    }
};
int main()
{
    Solution obj;
    return 0;
}