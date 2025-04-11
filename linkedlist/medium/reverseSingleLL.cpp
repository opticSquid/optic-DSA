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
    ListNode *reverseList(ListNode *head)
    {
        ListNode *prev = NULL;
        while (head != NULL)
        {
            ListNode *front = head->next;
            head->next = prev;
            prev = head;
            head = front;
        }
        return prev;
    }
};
void printLinkedList(ListNode *head);
int main()
{
    ListNode *one = new ListNode(1);
    ListNode *two = new ListNode(2);
    ListNode *three = new ListNode(3);
    ListNode *four = new ListNode(4);
    one->next = two;
    two->next = three;
    three->next = four;
    cout << "before reversing: " << endl;
    printLinkedList(one);
    Solution obj;
    ListNode *reversed = obj.reverseList(one);
    cout << "after reversing: " << endl;
    printLinkedList(reversed);
    return 0;
}

void printLinkedList(ListNode *head)
{
    ListNode *current = head;
    while (current != nullptr)
    {
        cout << current->val << " -> ";
        current = current->next;
    }
    cout << "NULL" << endl;
}