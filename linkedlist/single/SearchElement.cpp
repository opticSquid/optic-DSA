#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

class Solution
{
public:
    // Function to count nodes of a linked list.
    bool searchKey(int n, struct Node *head, int key)
    {
        while (head->next != NULL)
        {
            if (head->data == key)
                return true;
            head = head->next;
        }
        return false;
    }
};
int main()
{
    Solution obj;
    return 0;
}