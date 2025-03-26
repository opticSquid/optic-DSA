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
    // Function to find the length of a loop in the linked list.
    int countNodesinLoop(Node *head)
    {
        Node *fast, *slow;
        fast = slow = head;
        while (fast != nullptr && fast->next != nullptr)
        {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow)
            {
                int len = 0;
                while (fast != slow)
                {
                    fast = fast->next;
                    len++;
                }
                return len;
            }
        }
        return 0;
    }
};
int main()
{
    Solution obj;
    return 0;
}