#include <bits/stdc++.h>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution
{
public:
    ListNode *deleteMiddle(ListNode *head)
    {
        // If the list is empty or has only one node,
        // return NULL as there is no middle node to delete
        if (head == NULL || head->next == NULL)
        {
            return NULL;
        }

        // Initialize slow and fast pointers
        ListNode *slow = head;
        ListNode *fast = head;
        fast = head->next->next;

        // Move 'fast' pointer twice as fast as 'slow'
        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Delete the middle node by skipping it
        slow->next = slow->next->next;
        return head;
    }
};
int main()
{
    Solution obj;
    return 0;
}