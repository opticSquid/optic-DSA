#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int val)
    {
        data = val;
        this->next = NULL;
        this->prev = NULL;
    }
};
class Solution
{
public:
    // Function to delete a node at given position.
    Node *deleteNode(Node *head, int x)
    {
        Node *node = head;
        int count = 1;
        while (count < x && node->next != NULL)
        {
            node = node->next;
            count++;
        }
        Node *prevNode = node->prev;
        Node *nextNode = node->next;
        if (node->prev == NULL)
        {
            nextNode->prev = NULL;
            head = nextNode;
        }
        else if (node->next == NULL)
        {
            prevNode->next = NULL;
        }
        else
        {
            prevNode->next = nextNode;
            nextNode->prev = prevNode;
        }
        delete node;
        return head;
    }
};
int main()
{
    Solution obj;
    return 0;
}