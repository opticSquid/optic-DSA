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
    int getCount(struct Node *head)
    {
        if (head == NULL)
        {
            return 0;
        }
        int count = 1;
        while (head->next != NULL)
        {
            count++;
            head = head->next;
        }
        return count;
    }
};
int main()
{
    Solution obj;
    return 0;
}