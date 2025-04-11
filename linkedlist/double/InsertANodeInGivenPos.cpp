#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
    Node(int x)
    {
        data = x;
        next = prev = NULL;
    }
};
class Solution
{
public:
    // Function to insert a new node at given position in doubly linked list.
    Node *addNode(Node *head, int pos, int data)
    {
        Node *prevNode = head;
        int count = 0;
        while (count < pos && prevNode->next != NULL)
        {
            prevNode = prevNode->next;
            count++;
        }
        if (prevNode->next == NULL)
        {
            Node *newNode = new Node(data);
            newNode->prev = prevNode;
            prevNode->next = newNode;
        }
        else
        {
            Node *orgNextNode = prevNode->next;
            Node *newNode = new Node(data);
            newNode->prev = prevNode;
            orgNextNode->prev = newNode;
            prevNode->next = newNode;
            newNode->next = orgNextNode;
        }
        return head;
    }
};
int main()
{
    vector<int> arr = {4, 7, 3, 1, 4, 9, 1, 2, 4, 8, 6, 1};
    Node *head = new Node(arr[0]);
    Node *prevNode = head;
    for (int i = 1; i < arr.size(); i++)
    {
        Node *node = new Node(arr[i]);
        node->prev = prevNode;
        prevNode->next = node;
        prevNode = node;
    }
    Solution obj;
    head = obj.addNode(head, 9, 8);
    while (head->next != NULL)
    {
        cout << head->data << "->";
        head = head->next;
    }
    cout << endl;
    return 0;
}