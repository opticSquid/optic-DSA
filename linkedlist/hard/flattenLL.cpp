#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node *next;
    struct Node *bottom;

    Node(int x)
    {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};
class Solution
{
private:
    Node *merge(Node *list1, Node *list2)
    {
        Node *dummyNode = new Node(-1);
        Node *res = dummyNode;
        while (list1 != nullptr && list2 != nullptr)
        {
            if (list1->data < list2->data)
            {
                res->bottom = list1;
                res = list1;
                list1 = list1->bottom;
            }
            else
            {
                res->bottom = list2;
                res = list2;
                list2 = list2->bottom;
            }
            res->next = nullptr;
        }

        if (list1 != nullptr)
        {
            res->bottom = list1;
        }
        else
        {
            res->bottom = list2;
        }

        if (dummyNode->bottom != nullptr)
        {
            dummyNode->bottom->next = nullptr;
        }
        return dummyNode->bottom;
    }

public:
    // Function which returns the  root of the flattened linked list.
    Node *flatten(Node *root)
    {
        if (root == nullptr || root->next == nullptr)
        {
            return root;
        }
        Node *mergedRoot = flatten(root->next);
        root = merge(root, mergedRoot);
        return root;
    }
};
int main()
{
    Solution obj;
    return 0;
}