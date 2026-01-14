#include <bits/stdc++.h>
#include "../shared/tree-node.hpp"
using namespace std;
class Solution
{
private:
    // A helper to manually slice the string by commas
    // Passing 'pos' by reference (&) updates it automatically for the next call
    string getNextToken(const string &data, int &pos)
    {
        int start = pos;
        while (pos < data.size() && data[pos] != ',')
        {
            pos++;
        }
        // Extract the substring
        string token = data.substr(start, pos - start);
        // Move past the comma for the next turn
        pos++;
        return token;
    }

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
        res.reserve(10000);
        while (!q.empty())
        {
            TreeNode *node = q.front();
            q.pop();
            if (node == nullptr)
            {
                res.append("null,");
            }
            else
            {
                res.append(to_string(node->val)).append(",");
                q.push(node->left);
                q.push(node->right);
            }
        }
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        if (data.empty())
        {
            return nullptr;
        }
        int pos = 0;
        int n = data.size();
        string val;

        val = getNextToken(data, pos);

        TreeNode *root = new TreeNode(stoi(val));

        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            TreeNode *node = q.front();
            q.pop();

            val = getNextToken(data, pos);

            if (val != "null")
            {
                TreeNode *leftNode = new TreeNode(stoi(val));
                node->left = leftNode;
                q.push(leftNode);
            }
            val = getNextToken(data, pos);
            if (val != "null")
            {
                TreeNode *rightNode = new TreeNode(stoi(val));
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