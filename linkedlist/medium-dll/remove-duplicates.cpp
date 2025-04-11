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
        next = prev = nullptr;
    }
};
class Solution
{
public:
    Node *removeDuplicates(Node *head)
    {
        Node *temp = head;
        while (temp != nullptr && temp->next != nullptr)
        {
            Node *nextNode = temp->next;
            Node *first = temp;
            while (nextNode != nullptr && temp->data == nextNode->data)
            {
                Node *dup = nextNode;
                nextNode = nextNode->next;
                delete dup;
            }
            temp->next = nextNode;
            if (nextNode != nullptr)
            {
                nextNode->prev = temp;
            }
            temp = temp->next;
        }
        return head;
    }
};
int main()
{
    vector<int> vec = {1, 1, 1, 2, 3, 4};
    Node *prev = new Node(vec[0]);
    Node *head = prev;
    for (int i = 1; i < vec.size(); i++)
    {
        Node *node = new Node(vec[i]);
        node->prev = prev;
        prev->next = node;
        prev = node;
    }
    Solution obj;
    obj.removeDuplicates(head);
    return 0;
}