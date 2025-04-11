#include <bits/stdc++.h>
using namespace std;
class DLLNode
{
public:
    int data;
    DLLNode *next;
    DLLNode *prev;

    DLLNode(int val)
    {
        data = val;
        this->next = NULL;
        this->prev = NULL;
    }
};

class Solution
{
public:
    // Function to reverse a doubly linked list
    DLLNode *reverseDLL(DLLNode *head)
    {
        if (head == NULL || head->next == NULL)
        {
            return head;
        }
        DLLNode *current = head;
        DLLNode *prev = NULL;
        while (current != NULL)
        {
            prev = current->prev;
            current->prev = current->next;
            current->next = prev;
            current = current->prev;
        }
        return prev->prev;
    }
};
int main()
{
    Solution obj;
    return 0;
}