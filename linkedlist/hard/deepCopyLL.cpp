#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
class Solution
{
private:
    void insertCopyInBetween(Node *head)
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            Node *nextEle = temp->next;
            Node *copy = new Node(temp->val);
            copy->next = nextEle;
            temp->next = copy;
            temp = nextEle;
        }
    }
    void connectRandomPointers(Node *head)
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            Node *copyNode = temp->next;
            if (temp->random != nullptr)
            {
                copyNode->random = temp->random;
            }
            else
            {
                copyNode->random = nullptr;
            }
            temp = temp->next->next;
        }
    }

    Node *getDeepCopyList(Node *head)
    {
        Node *temp = head;
        Node *dummyNode = new Node(-1);
        Node *res = dummyNode;
        while (temp != nullptr)
        {
            res->next = temp->next;
            res = res->next;
            temp->next = temp->next->next;
            temp = temp->next;
        }
        return dummyNode->next;
    }

public:
    Node *copyRandomList(Node *head)
    {
        if (head == nullptr)
        {
            return head;
        }
        insertCopyInBetween(head);
        connectRandomPointers(head);
        return getDeepCopyList(head);
    }
};
int main()
{
    Solution obj;
    return 0;
}