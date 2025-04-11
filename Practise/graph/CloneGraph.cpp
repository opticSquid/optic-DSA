#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int val;
    vector<Node *> neighbors;
    Node()
    {
        val = 0;
        neighbors = vector<Node *>();
    }
    Node(int _val)
    {
        val = _val;
        neighbors = vector<Node *>();
    }
    Node(int _val, vector<Node *> _neighbors)
    {
        val = _val;
        neighbors = _neighbors;
    }
};
class Solution
{
private:
    Node *dfs(Node *curN, unordered_map<Node *, Node *> &mp)
    {
        vector<Node *> neighbours;
        Node *clone = new Node(curN->val);
        mp[curN] = clone;
        for (Node *it : curN->neighbors)
        {
            if (mp.find(it) != mp.end())
            {
                neighbours.push_back(mp[it]);
            }
            else
            {
                neighbours.push_back(dfs(it, mp));
            }
        }
        clone->neighbors = neighbours;
        return clone;
    }

public:
    Node *cloneGraph(Node *node)
    {
        if (node == NULL)
            return NULL;
        unordered_map<Node *, Node *> mp;
        if (node->neighbors.size() == 0)
        {
            return new Node(node->val);
        }
        return dfs(node, mp);
    }
};
int main()
{
    Node one(1), two(2), three(3), four(4), five(5);
    one.neighbors = {&two};
    two.neighbors = {&one, &three, &four};
    three.neighbors = {&two, &five};
    four.neighbors = {&two, &five};
    five.neighbors = {&three, &four};
    Solution obj;
    Node *cloneHead = obj.cloneGraph(&one);
    delete cloneHead;
    return 0;
}