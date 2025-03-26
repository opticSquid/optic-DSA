#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
private:
    ListNode *findStart(ListNode *fast, ListNode *slow)
    {
        while (fast != slow)
        {
            fast = fast->next;
            slow = slow->next;
        }
        return slow;
    }

public:
    ListNode *detectCycle(ListNode *head)
    {
        ListNode *fast = head;
        ListNode *slow = head;
        while (fast != nullptr && fast->next != nullptr)
        {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow)
            {
                return findStart(fast, head);
            }
        }
        return nullptr;
    }
};
int main()
{
    Solution obj;
    return 0;
}