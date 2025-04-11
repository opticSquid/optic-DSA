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
    void *deleteAllOccurOfX(Node **head_ref, int x)
    {
        Node *temp = *head_ref;
        while (temp)
        {
            if (temp->data == x)
            {
                if (temp == *head_ref)
                {
                    *head_ref = temp->next;
                }
                Node *next = temp->next;
                Node *prev = temp->prev;
                if (next)
                {
                    next->prev = prev;
                }
                if (prev)
                {
                    prev->next = next;
                }
                delete temp;
                temp = next;
            }
            else
            {
                temp = temp->next;
            }
        }
    }
};

int main()
{

    Solution obj;
    return 0;
}