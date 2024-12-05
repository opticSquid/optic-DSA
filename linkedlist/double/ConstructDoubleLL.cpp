#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    Node *prev;
    int data;
    Node *next;

    Node()
    {
        prev = NULL;
        data = 0;
        next = NULL;
    }

    Node(int value)
    {
        prev = NULL;
        data = value;
        next = NULL;
    }
};

class Solution
{
public:
    Node *constructDLL(vector<int> &arr)
    {
        Node *prevNode = new Node(arr[0]);
        Node *head = prevNode;
        for (int i = 1; i < arr.size(); i++)
        {
            Node *node = new Node(arr[1]);
            node->prev = prevNode;
            prevNode->next = node;
            prevNode = node;
        }
        return head;
    }
};
int main()
{
    Solution obj;
    return 0;
}