#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
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
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (head == nullptr)
            return nullptr;
        ListNode *node = head;
        while (node->next != nullptr)
        {
            ListNode *nextNode = node->next;
            if (node->val == node->next->val)
            {
                node->next = nextNode->next;
                delete (nextNode);
            }
            else
            {
                node = node->next;
            }
        }
        return head;
    }
};
int main()
{
    Solution obj;
    return 0;
}