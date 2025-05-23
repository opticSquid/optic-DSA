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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *fast, *slow;
        fast = slow = head;
        for (int i = 0; i < n; i++)
        {
            fast = fast->next;
        }

        // If fast becomes NULL,
        // the Nth node from the end is the head
        if (fast == nullptr)
        {
            return head->next;
        }
        while (fast->next != nullptr)
        {
            fast = fast->next;
            slow = slow->next;
        }

        ListNode *delNode = slow->next;
        slow->next = slow->next->next;
        delete delNode;
        return head;
    }
};
int main()
{
    Solution obj;
    return 0;
}