#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};
class Solution
{
public:
    Node *insertAtEnd(Node *head, int x)
    {
        if (head == NULL)
        {
            return new Node(x);
        }
        Node *node = head;
        while (node->next != NULL)
        {
            node = node->next;
        }
        node->next = new Node(x);
        return head;
    }
};
int main()
{
    Solution obj;
    return 0;
}