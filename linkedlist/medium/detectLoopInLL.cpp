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
public:
    bool hasCycle(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast != nullptr && fast->next != nullptr)
        {
            fast = fast->next->next;
            slow = slow->next;
            if (slow == fast)
            {
                return true;
            }
        }
        return false;
    }
};
int main()
{
    Solution obj;
    return 0;
}