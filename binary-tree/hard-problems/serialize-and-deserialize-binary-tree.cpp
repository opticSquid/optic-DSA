#include <bits/stdc++.h>
#include "../shared/tree-node.hpp"
using namespace std;
class Solution
{
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        if (root == nullptr)
        {
            return "";
        }
        queue<TreeNode *> q;
        string res;
        q.push(root);
        while (!q.empty())
        {
            TreeNode *node = q.front();
            q.pop();
            if (node == nullptr)
            {
                res += "null,";
            }
            else
            {
                res += to_string(node->val) + ",";
                q.push(node->left);
                q.push(node->right);
            }
        }
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        if (data == "")
        {
            return nullptr;
        }
        stringstream s(data);
        string str;
        getline(s, str, ',');
        TreeNode *root = new TreeNode(stoi(str));

        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            TreeNode *node = q.front();
            q.pop();

            getline(s, str, ',');

            if (str != "null")
            {
                TreeNode *leftNode = new TreeNode(stoi(str));
                node->left = leftNode;
                q.push(leftNode);
            }

            getline(s, str, ',');
            if (str != "null")
            {
                TreeNode *rightNode = new TreeNode(stoi(str));
                node->right = rightNode;
                q.push(rightNode);
            }
        }
        return root;
    }
};
int main()
{
    Solution obj;
    return 0;
}